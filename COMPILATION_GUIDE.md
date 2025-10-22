# NewCity Compilation Guide

This document provides comprehensive instructions for compiling the NewCity project on Linux systems.

## Prerequisites

- CMake 3.5 or higher
- C++23 compatible compiler (GCC 11+ or Clang 14+)
- Required system libraries: OpenGL, OpenAL, Threads
- Make or Ninja build system

## Quick Start

### Debug Build (Recommended for Development)
```bash
cd /home/nmonti/GitHub/newcity-evo/build
make -j$(nproc)
```

### Release Build (Optimized)
```bash
cd /home/nmonti/GitHub/newcity-evo/build-release
make -j$(nproc)
```

## Detailed Compilation Options

### 1. Using Existing Build Directories

The project comes with pre-configured build directories:

#### Debug Build
```bash
cd /home/nmonti/GitHub/newcity-evo/build
make -j$(nproc)
```

#### Release Build
```bash
cd /home/nmonti/GitHub/newcity-evo/build-release
make -j$(nproc)
```

#### Clean + Rebuild
```bash
cd /home/nmonti/GitHub/newcity-evo/build
make clean && make -j$(nproc)
```

### 2. Fresh CMake Configuration

If you need to reconfigure the build from scratch:

#### Debug Build
```bash
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j$(nproc)
```

#### Release Build
```bash
mkdir -p build-release && cd build-release
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
```

## Build Targets

The project builds two main executables:

- **`newcity`** - Main game executable
- **`game_test`** - Test suite executable

Both executables are automatically copied to the `src/` directory after successful compilation.

## Compiler Flags

### Debug Build Flags
- `-g` - Debug symbols
- `-std=c++23` - C++23 standard
- `-Werror=return-type` - Treat missing return statements as errors
- `-Wshadow` - Warn about variable shadowing
- `-D_GLIBCXX_DEBUG` - Enable debug mode for libstdc++
- `-DLP_DEBUG` - Enable debug features
- `-fno-omit-frame-pointer` - Preserve frame pointers for debugging

### Release Build Flags
- `-O3` - Maximum optimization
- `-fno-rtti` - Disable runtime type information
- `-fno-exceptions` - Disable exception handling
- `-std=c++23` - C++23 standard

## Platform-Specific Notes

### Linux (Current Configuration)
- Uses GCC/Clang with GNU Make
- Static linking enabled (`-static`)
- C++23 standard: `-std=c++23`

### Windows (Cross-compilation)
- Uses MSVC-style flags
- C++23 standard: `/std:c++23`
- Additional Windows-specific libraries linked

## Performance Tips

1. **Use parallel compilation**: Always use `-j$(nproc)` to utilize all CPU cores
2. **Choose appropriate build type**: Use Debug for development, Release for performance
3. **Clean builds**: Use `make clean` when switching between build types or after major changes

## Troubleshooting

### Common Issues

1. **Missing dependencies**: Ensure OpenGL, OpenAL, and development headers are installed
2. **Compiler version**: Verify your compiler supports C++23 features
3. **Build directory**: Don't build in the source directory (CMake will prevent this)

### Build Verification

After successful compilation, you should see:
```
[100%] Built target newcity
```

The executables will be available in:
- `build/newcity` (debug)
- `build-release/newcity` (release)
- `src/newcity` (copied automatically)

## External Dependencies

The project includes these external libraries:
- **Boost** (1.74.0) - C++ libraries
- **GLFW** (3.3) - Window management
- **GLEW** (1.13.0) - OpenGL extension loading
- **FreeType** - Font rendering
- **GLM** (0.9.7.1) - OpenGL mathematics
- **Lua** (5.3.5) - Scripting
- **Steam API** - Steam integration
- **spdlog** (1.5.0) - Logging

All dependencies are included in the `external/` directory and built automatically.

## Development Workflow

1. **Make changes** to source code in `src/`
2. **Compile** using one of the commands above
3. **Test** the executable in `src/newcity`
4. **Debug** using debug symbols (Debug build only)

## Notes

- The project uses CMake as the build system
- All external dependencies are statically linked
- Steam integration is included but can be disabled via preprocessor flags
- The build system automatically handles platform differences
- C++23 standard is enforced on all platforms for consistency

---

*Last updated: $(date)*
*Project: NewCity Evolution*
