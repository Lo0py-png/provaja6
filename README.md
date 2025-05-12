# provaja6 – random demo repo 🤷‍♂️

hi there!
this is just a tiny c++ sandbox i threw together for my software-engineering lab.
goal: show off github actions with multi-job ci (linux + my own windows pc). nothing pro, just works.

---

## folders ‘n files

```
src/          → main.cpp        # little console app (prints 2+3)
tests/        → test_main.cpp   # asserts add(2,3)==5
.github/
  workflows/
    ci.yml    → the magic ci pipeline
```

---

## workflow (plain english)

| job               | runs on                  | does what                                                                                        |
| ----------------- | ------------------------ | ------------------------------------------------------------------------------------------------ |
| **linux-build**   | github’s ubuntu runner   | installs g++, cppcheck → lints code → builds app + test → runs test → uploads build/ as artifact |
| **windows-build** | my self-hosted runner 💻 | fires up msvc → builds same code → runs test → uploads build/                                    |

trigger: **every push, any branch**
if anything fails (lint, compile, unit-test) => red ❌

---

## self-hosted runner cheat-sheet (so i don’t forget)

```powershell
# run these in an admin powershell
mkdir C:\actions-runner
cd    C:\actions-runner
Invoke-WebRequest \
  -Uri https://github.com/actions/runner/releases/download/v2.323.0/actions-runner-win-x64-2.323.0.zip \
  -OutFile runner.zip
tar -xf runner.zip
.\config.cmd --url https://github.com/Lo0py-png/provaja6 --token <token-from-github>
.\run.cmd        # keep this window open (or use .\svc install ; .\svc start)
```

---

## quick poke-test

```bash
echo "// poke $(date)" >> src/main.cpp
git add src/main.cpp
git commit -m "docs: poke ci"
git push
# now watch the Actions tab go green (or red if you broke stuff 😅)
```

that’s literally it. have fun poking around!
