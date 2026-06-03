#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${BUILD_DIR:-build}"

"${ROOT}/scripts/build.sh"
(cd "${ROOT}" && "${ROOT}/${BUILD_DIR}/test_environment" ${1:+--gtest_filter="$1.*"})
