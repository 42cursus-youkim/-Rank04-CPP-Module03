import shutil
from pathlib import Path

TARGET = "scavTrap"

working_dir = Path(__file__).parent
module = working_dir.parent

cpp = Path("src") / f"{TARGET}.cpp"
hpp = Path("include") / f"{TARGET}.hpp"

cpp_text = (working_dir / cpp).read_text()
hpp_text = (working_dir / hpp).read_text()

for ex in (f"ex{i:02}" for i in range(int(str(working_dir)[-1]) + 1, 4)):
    (module / ex / cpp).write_text(cpp_text)
    (module / ex / hpp).write_text(hpp_text)
    print(f"copied {TARGET} to {ex}")
