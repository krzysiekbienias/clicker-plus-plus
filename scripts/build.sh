#!/usr/bin/env bash
# Configure (if needed) and build clicker-plus-plus (Cursor / terminal workflow).
#
# Build dirs:
#   build/              — default here (Cursor, scripts, compile_commands.json)
#   cmake-build-debug/  — CLion (configure & run from IDE; do not use this script)
#
# Usage:
#   ./scripts/build.sh              # build (Debug, build/)
#   ./scripts/build.sh --configure  # re-run cmake before build
#   BUILD_DIR=cmake-build-debug ./scripts/build.sh   # only if you really need CLion dir from CLI

set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${BUILD_DIR:-build}"
BUILD_TYPE="${BUILD_TYPE:-Debug}"
GENERATOR="${GENERATOR:-Ninja}"

cd "$ROOT"

configure() {
  echo "⚙️  Configuring: $BUILD_DIR ($BUILD_TYPE, $GENERATOR)"
  cmake -S . -B "$BUILD_DIR" \
    -G "$GENERATOR" \
    -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
}

if [[ "${1:-}" == "--configure" || "${1:-}" == "-c" ]]; then
  configure
  shift
fi

if [[ ! -f "$BUILD_DIR/CMakeCache.txt" ]]; then
  configure
fi

echo "🔨 Building in $BUILD_DIR ..."
cmake --build "$BUILD_DIR" "$@"

if [[ "$BUILD_DIR" == "build" && -f "$BUILD_DIR/compile_commands.json" ]]; then
  ln -sf "$BUILD_DIR/compile_commands.json" "$ROOT/compile_commands.json"
fi

echo "✅ Done."
