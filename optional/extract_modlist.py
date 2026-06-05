import re
import sys
from pathlib import Path

html_path = Path(__file__).parent / "modlist.html"
if len(sys.argv) > 1:
    html_path = Path(sys.argv[1])

html = html_path.read_text(encoding="utf-8")

# Extract only the mod-list section (not dlc-list)
mod_section = re.search(r'<div class="mod-list">(.*?)</div>', html, re.DOTALL)
if not mod_section:
    print("ERROR: mod-list section not found", file=sys.stderr)
    sys.exit(1)

# Extract Steam Workshop IDs from href attributes only (URL also appears as link text)
ids = re.findall(r'href="https://steamcommunity\.com/sharedfiles/filedetails/\?id=(\d+)"', mod_section.group(1))

if not ids:
    print("ERROR: no mods found", file=sys.stderr)
    sys.exit(1)

load_mods = ";".join(ids)
workshop_items = "\n".join(ids)

output = f"{load_mods}\n\n{workshop_items}"
output_path = html_path.with_name("modlist_output.txt")
output_path.write_text(output, encoding="utf-8")
print(f"Found {len(ids)} mods -> {output_path}", file=sys.stderr)
