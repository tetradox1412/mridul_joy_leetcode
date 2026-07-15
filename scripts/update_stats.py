#!/usr/bin/env python3
"""
Recomputes repo stats (problems solved, topics covered, difficulty split)
straight from the folder structure and README.md, then rewrites the block
between <!--STATS:START--> and <!--STATS:END--> in README.md.

Safe to run repeatedly: if nothing changed, it produces byte-identical
output, so the GitHub Action's "commit only if there's a diff" step
naturally no-ops instead of creating empty commits.
"""

import os
import re
import sys

README_PATH = "README.md"
STATS_START = "<!--STATS:START-->"
STATS_END = "<!--STATS:END-->"

TOPICS_START = "<!---LeetCode Topics Start-->"
TOPICS_END = "<!---LeetCode Topics End-->"

PROBLEM_FOLDER_RE = re.compile(r"^\d{4}-")
DIFFICULTY_BADGE_RE = re.compile(r"Difficulty-(Easy|Medium|Hard)", re.IGNORECASE)
DIFFICULTY_LABEL_RE = re.compile(r"difficulty[:\s]+\**(Easy|Medium|Hard)", re.IGNORECASE)


def get_problem_folders(root="."):
    return sorted(
        d
        for d in os.listdir(root)
        if os.path.isdir(os.path.join(root, d)) and PROBLEM_FOLDER_RE.match(d)
    )


def get_difficulty(folder):
    readme_path = os.path.join(folder, "README.md")
    if not os.path.exists(readme_path):
        return "Unknown"

    with open(readme_path, encoding="utf-8", errors="ignore") as f:
        content = f.read()

    match = DIFFICULTY_BADGE_RE.search(content) or DIFFICULTY_LABEL_RE.search(content)
    if match:
        return match.group(1).capitalize()

    for level in ("Easy", "Medium", "Hard"):
        if re.search(rf"\b{level}\b", content):
            return level

    return "Unknown"


def get_topic_count(readme_content):
    match = re.search(
        re.escape(TOPICS_START) + r"(.*?)" + re.escape(TOPICS_END),
        readme_content,
        re.DOTALL,
    )
    if not match:
        return 0
    headers = re.findall(r"^##\s+.+$", match.group(1), re.MULTILINE)
    return len(headers)


def build_stats_block(folders, topic_count):
    counts = {"Easy": 0, "Medium": 0, "Hard": 0, "Unknown": 0}
    for folder in folders:
        counts[get_difficulty(folder)] += 1

    lines = [
        STATS_START,
        "",
        "| Metric | Count |",
        "| --- | --- |",
        f"| Problems solved | {len(folders)} |",
        f"| Distinct topics tagged | {topic_count} |",
        f"| Easy | {counts['Easy']} |",
        f"| Medium | {counts['Medium']} |",
        f"| Hard | {counts['Hard']} |",
    ]

    if counts["Unknown"]:
        lines.append(f"| Unclassified | {counts['Unknown']} |")

    lines += ["", STATS_END]
    return "\n".join(lines)


def main():
    if not os.path.exists(README_PATH):
        sys.exit(f"error: {README_PATH} not found in current directory")

    with open(README_PATH, encoding="utf-8") as f:
        content = f.read()

    if STATS_START not in content or STATS_END not in content:
        sys.exit(
            f"error: could not find {STATS_START} / {STATS_END} markers in "
            f"{README_PATH}. Add them once (see README) and re-run."
        )

    folders = get_problem_folders()
    topic_count = get_topic_count(content)
    new_block = build_stats_block(folders, topic_count)

    pattern = re.compile(re.escape(STATS_START) + r".*?" + re.escape(STATS_END), re.DOTALL)
    updated_content = pattern.sub(lambda _: new_block, content)

    if updated_content != content:
        with open(README_PATH, "w", encoding="utf-8") as f:
            f.write(updated_content)
        print(f"Updated stats: {len(folders)} problems, {topic_count} topics.")
    else:
        print("Stats unchanged, nothing to commit.")


if __name__ == "__main__":
    main()
