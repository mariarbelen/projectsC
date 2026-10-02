#!/usr/bin/env bash
# Smoke tests: run each program with scripted input and check its output.
# Usage: make test   (or ./tests/run_tests.sh after `make`)

set -u
cd "$(dirname "$0")/.."

passed=0
failed=0

# expect NAME PROGRAM INPUT EXPECTED_SUBSTRING
expect() {
    local name=$1 program=$2 input=$3 expected=$4
    local output
    output=$(printf '%b' "$input" | timeout 5 "bin/$program" 2>&1)
    if [[ "$output" == *"$expected"* ]]; then
        passed=$((passed + 1))
        echo "PASS  $name"
    else
        failed=$((failed + 1))
        echo "FAIL  $name"
        echo "      expected to find: $expected"
        echo "      actual output:"
        echo "$output" | sed 's/^/        /'
    fi
}

# Exercises
expect "circle area"            shape_areas      ""                       "Circle with diameter 4:              12.57"
expect "heron's formula"        shape_areas      ""                       "Triangle with sides 4, 6, 8:         11.62"
expect "free cookies"           cookie_order     "25\nn\n"                "You also get 2 free cookie(s)"
expect "cookie dozens"          cookie_order     "25\nn\n"                "2 dozen and 3 loose cookie(s)"
expect "chocolate chips"        cookie_order     "25\nn\n"                "270 chocolate chips"
expect "same-day time diff"     time_difference  "0900\n1745\n"           "is 525 minutes (8h 45m)"
expect "overnight time diff"    time_difference  "2330\n0015\n"           "is 45 minutes"
expect "invalid time rejected"  time_difference  "2575\n0100\n"           "Invalid time"
expect "swap case"              swap_case        "Hello World 123\n"      "hELLO wORLD 123"
expect "word count"             word_counter     "  Hi there   friend \n" "Number of words: 3"
expect "letter count"           word_counter     "Hello\n"                "l: 2"
expect "phone found"            phone_lookup     "ash williams\nn\n"      "The number is: 333-2323"
expect "phone not found"        phone_lookup     "Nobody\nn\n"            "Name not found."

# Projects
expect "overtime pay"           paycheck_calculator "20\n45\ns\n"         "Gross pay:                  \$    950.00"
expect "family insurance"       paycheck_calculator "20\n40\no\n"         "Take-home pay:              \$    238.40"
expect "progressive state tax"  salary_calculator "60000\n5\nn\nn\nn\n0\n" "State income tax:            2833.43"
expect "biweekly net pay"       salary_calculator "60000\n2\ny\no\ny\ns\nn\n5\n" "Net pay:                       1274.85"
expect "seat booking"           seat_reservation "3C\nQ\n"                "Seat 3C is booked."
expect "seat already taken"     seat_reservation "3C\n3c\nQ\n"            "That seat is occupied"
expect "seat out of range"      seat_reservation "9A\nQ\n"                "That seat does not exist"
expect "vowel count"            string_toolkit   "Hello, World 42\nA\nG\n" "3 vowel(s)"
expect "consonant count"        string_toolkit   "Hello, World 42\nB\nG\n" "7 consonant(s)"
expect "uppercase"              string_toolkit   "Hello\nC\nE\nG\n"       "HELLO"
expect "hollow square"          shape_drawer     "2\n3\n4\n"              "*   * "
expect "triangle"               shape_drawer     "3\n3\n4\n"              "* * * "
expect "rps plays all rounds"   rock_paper_scissors "3\nr\np\ns\n"        "Final result:"
expect "rps rejects bad move"   rock_paper_scissors "1\nx\nr\n"           "Please enter R, P or S"
expect "pet status"             virtual_pet      "Mochi\n1\n5\n"          "Mochi is feeling happy."
expect "pet feeding"            virtual_pet      "Mochi\n2\n1\n5\n"       "Mochi has been fed!"
expect "pet reaches old age"    virtual_pet      "Rex\n$(for i in $(seq 20); do printf '2\\n1\\n4\\n2\\n'; done)" "has lived a long"

echo
echo "$passed passed, $failed failed"
[[ $failed -eq 0 ]]
