load("@rules_cc//cc:defs.bzl", "cc_binary")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "FastBiomeTest",
    srcs = glob([
        "*.cc",
        "*.h",
    ]),
    copts = ["-std=c++20"],
    deps = ["//FastBiome"],
)
