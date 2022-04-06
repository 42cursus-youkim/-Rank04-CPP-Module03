from os import chdir, system
from pathlib import Path
from subprocess import run

TARGET = "clapTrap"

working_dir = Path(__file__).parent
module = working_dir.parent

cpp = Path("src") / f"{TARGET}.cpp"
hpp = Path("include") / f"{TARGET}.hpp"

cpp_text = (working_dir / cpp).read_text()
hpp_text = (working_dir / hpp).read_text()

for ex in (f"ex{i:02}" for i in range(int(str(working_dir)[-1]) + 1, 4)):
    cfile, hfile = (module / ex / cpp), (module / ex / hpp)
    cfile.write_text(cpp_text)
    hfile.write_text(hpp_text)
