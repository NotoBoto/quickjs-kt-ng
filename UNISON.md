# quickjs-kt-ng

Fork of [dokar3/quickjs-kt](https://github.com/dokar3/quickjs-kt) for [Unison](https://github.com/NotoBoto/unison):
the same Kotlin library, but on **quickjs-ng 0.12.1** instead of Bellard QuickJS, so book-source plugins behave
byte-for-byte the same on Android, in Unison Studio (PyPI `quickjs-ng==0.12.1.1`) and in tests (quickjs-emscripten ng).

Changes against upstream are limited to the engine (the Kotlin layer is untouched, so upstream merges stay easy):

- `quickjs/native/quickjs-ng/` — quickjs-ng v0.12.1 sources (the Bellard submodule stays next to it);
- `quickjs/native/CMakeLists.txt` — `-DQJS_ENGINE=ng|bellard`, default `ng`;
- `quickjs/native/common/qjs_compat.h` and `#ifdef QJS_NG` — the few C API differences
  (`JS_IsArray`/`JS_IsError` signatures, `JS_SetUncatchableError`, `bool` in the rejection tracker);
- `quickjs/build.gradle.kts` — `ndkVersion`, `commonTest` also runs as Android instrumented tests;
- `gradle.properties` — `android.overridePathCheck=true` (build from folders with non-ASCII names), version `1.0.18-ng.N`.

Build and test (JDK 21, Android SDK with NDK 30.0.16248370):

    ./gradlew :quickjs:assembleRelease              # quickjs/build/outputs/aar/quickjs-release.aar
    ./gradlew :quickjs:connectedDebugAndroidTest    # needs a device or emulator

Known, accepted test failures on ng (154 tests, 152 pass):
`QuickJsPropertiesTest.version` (expects Bellard's date-style version) and
`ModuleLoaderTest.resolveModuleGraphUsesCustomNormalizer` (ng calls the module normalizer for the entry twice;
Unison plugins are IIFE bundles without modules).

Updating upstream: merge its tag into `ng`, build, run the instrumented tests, bump `-ng.N`.
