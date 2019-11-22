from conans import ConanFile, CMake


class TargetConan(ConanFile):
    name = "linux_app"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    exports_sources = "*"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.definitions["CMAKE_BUILD_TYPE"] = self.settings.build_type
        cmake.definitions["PROJECT_CONFIG_ARCH"] = self.settings.arch
        cmake.configure()
        cmake.build()

    def requirements(self):
        self.requires("rapidjson/1.1.0@bincrafters/stable")
        self.requires("poco/1.9.4")
        self.requires("openssl/1.1.1d")
