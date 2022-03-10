// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "swift_algo",
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "swift_algo",
            targets: ["swift_algo"]),
    ],
    dependencies: [
        
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .target(
            name: "swift_algo", dependencies: []),
        .testTarget(name: "swift-algo-test", dependencies: ["swift_algo"]),
    ]
)
