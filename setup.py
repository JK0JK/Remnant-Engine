import json
from pathlib import Path

import subprocess

butano_plugin_data = {
    "plugin-name": "butano",
    "plugin-description": "Butano engine.",
    "plugin-credits": ["GValiente"],
    "plugin-version": "21.9.0",
    "plugin-repo": "https://github.com/GValiente/butano",
}

result = subprocess.run(["git", "clone", "https://github.com/GValiente/butano", "plugins/butano"])

# Directory containing this Python script
project_dir = Path(__file__).resolve().parent

plugin_dir = project_dir / "plugins" / "butano"
plugin_dir.mkdir(parents=True, exist_ok=True)

plugin_json = plugin_dir / "plugin.json"

with plugin_json.open("w", encoding="utf-8") as file:
    json.dump(butano_plugin_data, file, indent=4)
    file.write("\n")

print(f"Created: {plugin_json}")