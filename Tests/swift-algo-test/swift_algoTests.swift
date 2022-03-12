import XCTest
import swift_algo

final class swift_algoTests: XCTestCase {
    func testCreateMatrix() {
        var matrix : UnsafeMutablePointer<mat>?
        
        create_matrix(10, 10, &matrix)
        
        XCTAssertEqual(matrix?.pointee.rows, 10)
        
        free_matrix(matrix)
    }
    
    func testPicard() {
        var res : UnsafeMutablePointer<mat>?
        let n: Int32 = Int32(ceilf(fabsf(2 - 0) / 1e-4))
        
        res = algo_picard(0, 1e-4, n)
        
        let rows: Int = Int(res?.pointee.rows ?? 0), cols: Int = Int(res?.pointee.cols ?? 0)
        
        for row in UnsafeBufferPointer(start: res?.pointee.data, count: rows) {
            for elem in UnsafeBufferPointer(start: row, count: cols) {
            }
        }
        
    }

    static var allTests = [
        ("testExample", testCreateMatrix, testPicard),
    ]
}
