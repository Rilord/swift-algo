import XCTest
@testable import swift_algo

final class swift_algoTests: XCTestCase {
    func testExample() {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct
        // results.
        XCTAssertEqual(swift_algo().text, "Hello, World!")
    }

    static var allTests = [
        ("testExample", testExample),
    ]
}
