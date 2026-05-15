from pathlib import Path

FILE_PATH = Path(__file__).parent / "cba_settings.sqf"
PREFIX = "force force "


def transform_line(line: str) -> str:
    stripped = line.lstrip()

    if not stripped:
        return line

    if stripped.startswith("//"):
        return line

    if stripped.startswith(PREFIX):
        return line

    leading = line[: len(line) - len(stripped)]
    return f"{leading}{PREFIX}{stripped}"


def main() -> None:
    content = FILE_PATH.read_text(encoding="utf-8")
    lines = content.splitlines(keepends=True)
    updated_lines = [transform_line(line) for line in lines]

    if updated_lines != lines:
        FILE_PATH.write_text("".join(updated_lines), encoding="utf-8")
        print(f"Updated: {FILE_PATH}")
    else:
        print("No changes needed")


if __name__ == "__main__":
    main()
