[![Build Status](https://travis-ci.org/alan-if/alan.svg?branch=master)](https://travis-ci.org/alan-if/alan)[![Coverage Status](https://coveralls.io/repos/github/alan-if/alan/badge.svg?branch=master)](https://coveralls.io/github/alan-if/alan?branch=master)

# Alan — the Adventure Language

Alan is a language for developing and running interactive fiction,
a.k.a adventure games, i.e. the games are text-based, in the best of
worlds reads like interactive literature, and gives you "the best
graphics device available — the human brain".

## What is this?

This repository is part of the larger ALAN-IF set of repositories with
tools, examples and documentation for the Alan system.


This particular repository contains the source code and build
environment for the Alan compiler, interpreters and an Alan v2 to Alan
v3 source converter.

## How to build?

The build system is fairly self-configuring, you should be able to
just clone and 'make' on the following platform:

- Cygwin
- Msys2, both native and 32/64-bit Windows-compatible
- Linux, most flavours including WSL (Windows Subsystem for Linux)
- MacOS/Darwin, both native and with Homebrew GCC

To run unittests you need Cgreen, and to run all the regression tests you need a Java runtime.

## What's in the box?

From the repo you can build

- command line compiler and interpreter for your OS
- GLK-based interpreter, you need a GLK-library
- Gargoyle plug-in, which can be used instead of the plug-in that comes with Gargoyle

And if your environment allows cross-compilation to Windows (Cygwin, MSYS2 and most Linuxen can be made to do this, but you have to install the cross-compilation tools)

- WinArun, a WindowsGLK based GUI-interpreter
- WinAlan, a Windows "GUI" compiler (but a better choice is probably the AlanIDE)

## What's missing?

A lot probably, but I wanted this Readme to exist as quickly as
possible. Please, join, fork, pull request or file issues if there is
something you want included here.

# Useful Links

- [Alan website]
- [Alan Yahoo Group] — for community help, announcements and discussions.
- [Alan IF Development team] — GitHub profile and public projects.

## Documentation and Tutorials

- [Alan Docs] — GitHub repository for Alan documentation.
- _[The Alan Manual]_ — online-readable version of the latest _ALAN Adventure Language Reference Manual_.
- _[Alan Cookbook v2]_ — by [Anssi Räisänen].
- _[The Alan Beginner's Guide]_ — by Michael Arnaud (2006). [Tutorial source files available](https://github.com/alan-if/alan-docs/tree/master/alanguide/alanguide-code).
- _[Alan IDE Reference Guide]_ — by Robert DeFord (2018).

## Code Examples

- [Alan by Examples] — community driven collection of examples to learn Alan.
- [Samples & examples for Alan v3] — on Alan website.

## Libraries

- [Alan Standard Library] — by [Anssi Räisänen], GitHub repository.
- [Alan Library v0.6.2] — an earlier (but still working) library (2002–2007), mainly used to compile legacy adventures.
- [Alan StdLibLab] — experimental playground for variations on the Alan StdLib.
- [Alan Italian] — Italian port of the Alan StdLib.

## Editors

- [AlanIDE] — a complete Integrated Development Environment for Alan, built in Java/Eclipse. For more info, see:
    + [AlanIDE info page].
    + _[Alan IDE Reference Guide]_ — by Robert DeFord (2018), PDF document.
    + [AlanIDE sources] — JAVA source files, on GitHub.
- [Sublime Alan] — [Sublime Text 3] package for Alan 3 (working Alpha).

## Miscellanea

- [Alan Goodies] — a collection of assorted assets for Alan.
- [Alan Builder] — a [Travis CI] compliant build tool for Alan IF adventures projects.
- [Alan Bugs Testbed] — collaborative project to report and test Alan bugs.
- [Alan Repository Template] — A boilerplate for quickly creating Alan repositories with the right settings.

<!-----------------------------------------------------------------------------
                               REFERENCE LINKS
------------------------------------------------------------------------------>

<!-- ALAN -->

[Alan website]: https://www.alanif.se/ "Visit the Alan website"
[Alan IF]: https://www.alanif.se/ "Visit the Alan website"
[Alan Yahoo Group]: https://groups.yahoo.com/neo/groups/alan-if/info "Visit the Alan-IF group on Yahoo"
[Alan SDK]: https://www.alanif.se/download-alan-v3/development-kits "Go to the Alan SDK section of the Alan website"

[Artistic License 2.0]: https://opensource.org/licenses/Artistic-2.0

<!-- AlanIDE -->

[AlanIDE]: https://www.alanif.se/download-alan-v3/alanide "Go to the AlanIDE download page on Alan website"
[AlanIDE info page]: https://www.alanif.se/information/alanide/alanide-intro "View the AlanIDE information page on Alan website"
[Alan IDE Reference Guide]: https://github.com/alan-if/alan-docs/blob/master/ideguide/ideguide.pdf "Get the 'Alan IDE Reference Guide' (PDF format)"
[AlanIDE sources]: https://github.com/thoni56/alanide "Visit the AlanIDE source repository on GitHub"

<!-- Alan StdLib -->

[Alan Standard Library]: https://github.com/AnssiR66/AlanStdLib/ "Visit the official repository of the Alan Standard Library on GitHub"

<!-- misc Alan projects  -->

[Alan Bugs Testbed]: https://github.com/alan-if/alan-bugs-testbed "Visit the Alan Bugs Testbed project on GitHub"
[Alan Builder]: https://github.com/alan-if/Alan-Builder "Visit the Alan Builder project on GitHub"
[Alan Goodies]: https://github.com/tajmone/alan-goodies "Visit the Alan Goodies project on GitHub"
[Alan Italian]: https://github.com/tajmone/Alan3-Italian "Visit the Alan Italian project on GitHub"
[Alan Library v0.6.2]: https://github.com/tajmone/alan-goodies/tree/master/libs "View Alan Lib v0.6.2 at the 'Alan Goodies' project"
[Alan Repository Template]: https://github.com/alan-if/alan-repository-template "Visit the Alan Repository Template on GitHub"
[Alan StdLibLab]: https://github.com/tajmone/Alan-StdLibLab "Visit the Alan StdLibLab project on GitHub"
[Sublime Alan]: https://github.com/tajmone/sublime-alan "Visit the Sublime Alan project on GitHub"

<!-- Alan docs & tutorials -->

[Alan Docs]: https://github.com/alan-if/alan-docs "Visit the Alan Docs project on GitHub"
[The Alan Manual]: http://htmlpreview.github.io/?https://github.com/alan-if/alan-docs/blob/master/manual/manual.html "Live HTML preview of the Alan Manual"
[Alan Cookbook v2]: https://www.alanif.se/download-alan-v3/all-downloads/documentation/alan-cookbook-v2 "Go to the 'Alan Cookbook' download page on Alan website"

[The Alan Beginner's Guide]: http://htmlpreview.github.io/?https://github.com/alan-if/alan-docs/blob/master/alanguide/alanguide.html "Live HTML preview of the Alan Beginner's Guide"

[Samples & examples for Alan v3]: https://www.alanif.se/information/samples
[Alan by Examples]: https://github.com/alan-if/alan-by-examples "Visit the Alan by Examples project"

<!-- 3rd party tools & services -->

[Sublime Text 3]: https://www.sublimetext.com/ "Visit Sublime Text website"
[Travis CI]: https://travis-ci.com/ "Visit Travis CI website"

<!-- people and organizations -->

[Alan IF Development team]: https://github.com/alan-if "Visit the Alan Interactive Fiction Development team organization on GitHub"

[Anssi Räisänen]: https://github.com/AnssiR66 "View Anssi Räisänen's GitHub profile"
[Tristano Ajmone]: https://github.com/tajmone "View Tristano Ajmone's GitHub profile"
[Thomas Nilefalk]: https://github.com/thoni56 "View Thomas Nilefalk's GitHub profile"

<!-- EOF -->
