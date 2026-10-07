<div align="center">
  <h1>Ultimate X-Ray</h1>

  <h4><i>IX-Ray 1.6</i> game engine fork with more focus on stability and gameplay features</h4>

  <p>
    English
    |
    <a href="../doc/README.rus.md">
      Русский
    </a>
  </p>

  <p>
    <a href="https://github.com/uxray-team">
      <img src="../src/Assets/Splash_long.png" alt="Ultimate X-Ray" />
    </a>
  </p>

  <p>
    <a href="../LICENSE.md">
      <img src="https://img.shields.io/badge/License-Non--commercial-red.svg" alt="License" />
    </a>
    <a href="https://github.com/uxray-team/ultimate-xray/releases/latest">
      <img src="https://img.shields.io/github/v/release/uxray-team/ultimate-xray?include_prereleases&label=Release" alt="Latest release" />
    </a>
    <a href="https://github.com/uxray-team/ultimate-xray/releases">
      <img src="https://img.shields.io/github/downloads/uxray-team/ultimate-xray/total?label=Downloads" alt="All downloads" />
    </a>
    <a href="https://github.com/uxray-team/ultimate-xray/graphs/contributors">
      <img src="https://img.shields.io/github/contributors/uxray-team/ultimate-xray.svg?label=Contributors" alt="All Contributors" />
    </a>
    <br />
    <a href="https://github.com/uxray-team/ultimate-xray/actions/workflows/build-engine.yml">
      <img src="https://github.com/uxray-team/ultimate-xray/actions/workflows/build-engine.yml/badge.svg" alt="Build engine" />
    </a>
    <a href="https://github.com/uxray-team/ultimate-xray/actions/workflows/build-server.yml">
      <img src="https://github.com/uxray-team/ultimate-xray/actions/workflows/build-server.yml/badge.svg" alt="Build server" />
    </a>
    <br />
    <a href="https://github.com/uxray-team/ultimate-xray/actions/workflows/build-editors.yml">
      <img src="https://github.com/uxray-team/ultimate-xray/actions/workflows/build-editors.yml/badge.svg" alt="Build editors" />
    </a>
    <a href="https://github.com/uxray-team/ultimate-xray/actions/workflows/build-utilities.yml">
      <img src="https://github.com/uxray-team/ultimate-xray/actions/workflows/build-utilities.yml/badge.svg" alt="Build utilities" />
    </a>
    <a href="https://github.com/uxray-team/ultimate-xray/actions/workflows/build-plugins.yml">
      <img src="https://github.com/uxray-team/ultimate-xray/actions/workflows/build-plugins.yml/badge.svg" alt="Build plugins" />
    </a>
    <br />
    <a href="https://github.com/uxray-team/ultimate-xray/actions/workflows/nonunity-build.yml">
      <img src="https://github.com/uxray-team/ultimate-xray/actions/workflows/nonunity-build.yml/badge.svg" alt="Non-Unity build" />
    </a>
  </p>
</div>

## Overview

__Ultimate X-Ray__ is fork of __IX-Ray 1.6__ engine that aims to be more focused on player experience and providing stable tools for everyone

## Quick start

Latest release of the engine can be downloaded on the [releases page](https://github.com/uxray-team/ultimate-xray/releases)

## Ready-made builds

| Platform | Build | System | Files | Description |
| :--- | :--- | :--- | :--- | :--- |
| Call of Pripyat | Gamer | Windows x64 | [Engine+Assets](https://github.com/uxray-team/ultimate-xray/releases/download/r1.4/ixray-1.6-r1.4-engine-x64-game-cop.zip) | Ready-made engine build for players or necessary for the release of modifications. Archive contains the engine and assets for running the game |
| Call of Pripyat | Developer | Windows x64 | [Engine+Assets](https://github.com/uxray-team/ultimate-xray/releases/download/r1.4/ixray-1.6-r1.4-engine-x64-develop-cop.zip) | Ready-made engine build for developers, necessary for convenient modification development. Archive contains the engine and assets for launching the game |
| Clear Sky | Gamer | Windows x64 | [Engine+Assets](https://github.com/uxray-team/ultimate-xray/releases/download/r1.4/ixray-1.6-r1.4-engine-x64-game-cs.zip) | Ready-made engine build for players or necessary for the release of modifications. Archive contains the engine and assets for running the game |
| Clear Sky | Developer | Windows x64 | [Engine+Assets](https://github.com/uxray-team/ultimate-xray/releases/download/r1.4/ixray-1.6-r1.4-engine-x64-develop-cs.zip) | Ready-made engine build for developers, necessary for convenient modification development. Archive contains the engine and assets for launching the game |
| Shadow of Chernobyl | Gamer | Windows x64 | [Engine+Assets](https://github.com/uxray-team/ultimate-xray/releases/download/r1.4/ixray-1.6-r1.4-engine-x64-game-soc.zip) | Ready-made engine build for players or necessary for the release of modifications. Archive contains the engine and assets for running the game |
| Shadow of Chernobyl | Developer | Windows x64 | [Engine+Assets](https://github.com/uxray-team/ultimate-xray/releases/download/r1.4/ixray-1.6-r1.4-engine-x64-develop-soc.zip) | Ready-made engine build for developers, necessary for convenient modification development. Archive contains the engine and assets for launching the game |

You can read about the differences in [FAQ](https://github.com/uxray-team/ultimate-xray/blob/default/doc/faq.md#what-is-the-difference-between-the-game-player-and-developer-builds)

## Features

- Architectures support: __x64__
- Visual Studio 2019-2026 is supported
- __CMake__ build system
- Supported renderers: __DirectX 9.0c__, __DirectX 11__
- Improved performance and better FPS
- Fixed original bugs
- Increased level loading speed by 3-4 times
- Extended gameplay features
- Extended rendering features
    - Supported NVIDIA DLSS and AMD FidelityFX Super Resolution 3 (FSR3) Technologies
    - Supported PBR
    - Ambient Occlusion: SSAO, GTAO
    - Hashed Alpha-Test
    - Screen Space Local Reflections
    - Viewer Space Local Reflections
    - Cubemap 
    - Anti-aliasing: FXAA, SMAA, TAA
    - Supported __BC7__ compression format
- [Supported __TTF__ font system](https://github.com/uxray-team/ultimate-xray/wiki/Fonts)
- Supported in-game debugging tools
- [Extended opportunities for modmakers](ixray-team.github.io/ixray-1.6-stcop/)
- [Debugging tools support: __ASAN__, __RenderDoc__ and __LuaPanda__](https://ixray-team.github.io/ixray-1.6-stcop/main/integrations.html)
- [Extended __UI__ features](https://github.com/uxray-team/ultimate-xray/wiki/UI-%D0%9E%D0%B1%D1%89%D0%B5%D0%B5)
- [Extended __Lua__ features](https://github.com/uxray-team/ultimate-xray/wiki#%D1%81%D0%BA%D1%80%D0%B8%D0%BF%D1%82%D1%8B-lua)

- Addon system
- Modular particles
- [Lua Framework](https://ixray-team.github.io/ixray-1.6-stcop/scripting/ixr-framework/general-info.html)
- [__DLTX__ system](https://ixray-team.github.io/ixray-1.6-stcop/configs/dltx.html)
- [__XMLOverride__ system](https://ixray-team.github.io/ixray-1.6-stcop/configs/xml-override.html)
- Gamepad support
- Clear Sky and Shadow of Chernobyl support

## Addons

Ultimate X-Ray is compatible with most of the IX-Ray addons.

## Minimal system requirements

- OS: __Windows 7 SP1__ with installed [Platform Update](https://msdn.microsoft.com/en-us/library/windows/desktop/jj863687.aspx) or newer
- CPU: Supports __SSE2__ and newer instructions
- RAM: 4 GB
- GPU: Support for __Shader Model 3.0__ or newer
- GPU VRAM: 512 MB
- DirectX: __9.0с__ or newer

## Requirements

For launching:

- [OpenAL Driver](https://www.openal.org/downloads/)
- [Visual C++ Redistributable](https://www.microsoft.com/en-gb/download/details.aspx?id=48145)
- [DirectX End-User Runtime](https://www.microsoft.com/en-us/download/details.aspx?id=35)
- Install original game
- Delete in main folder of the game: `bin`, `gamedata` (if exists)
- Unpack archive to main folder of the game

For building:

- [Visual Studio 2022 (or 2026) Community Edition](https://visualstudio.microsoft.com/vs/community/)
  - Windows SDK 10.025+
- [Git](https://git-scm.com/downloads)
- [CMake](https://cmake.org/download/)

For development:

- [Visual Studio 2022 (or 2026) Community Edition](https://visualstudio.microsoft.com/vs/community/)
- [Git](https://git-scm.com/downloads)
- [CMake with CMake GUI](https://cmake.org/download/)

## Building

The project can be built in various ways. Choose the most convenient one and follow the steps

Download the repository firstly:

```sh
# From GitHub
git clone https://github.com/uxray-team/ultimate-xray.git
```

> [!IMPORTANT]
> System preparation before building
>
> To avoid errors, you must meet two requirements:
>
> 1. Disable third-party network tools:
>     - DPI bypass tools
>
> 2. Enable Long Paths support in Windows:
>     - This is the system limit of 260 characters for a file path
>     - Note: In newer versions of Windows 10/11, this setting is often enabled by default. You can check it by running the command `fsutil behavior query LongPathsEnabled` in a terminal with administrator rights. If it outputs `1`, it is enabled

### CMake GUI with Visual Studio

To generate `build` folder and solution:

- Open CMake GUI
- Press `Browse Source...` button and open folder with the project
- Select required options in `IXRAY` category
- Press `Configure` button and then `Generate` button

To build the project after generating solution:

- Open generated solution in Visual Sudio
- Select necessary build config
- Build solution

### Generate Visual Studio solution

To generate a solution with default settings from the console, follow the steps below:

  ```sh
  cmake -B build
  ```

To build the project after generating solution:

- Open generated solution in Visual Sudio
- Select necessary build config
- Build solution

## Changelog

All significant changes to this repository are documented in [this](./CHANGELOG.md) file

## License

Contents of this repository licensed under terms of the custom MIT-like non-commercial license unless otherwise specified. See [this](./LICENSE.md) file for details

## Support

Project is being supported by my enthusiasm
