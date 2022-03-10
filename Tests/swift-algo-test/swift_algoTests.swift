import XCTest
import swift_algo

final class swift_algoTests: XCTestCase {
    func testCreateMatrix() {
        var matrix : UnsafeMutablePointer<mat>?
        
        create_matrix(10, 10, &matrix)
        
        XCTAssertEqual(matrix?.pointee.rows, 10)
        
        free_matrix(matrix)
    }

    static var allTests = [
        ("testExample", testCreateMatrix),
    ]
}
