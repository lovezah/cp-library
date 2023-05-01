
constexpr int64_t cdiv(int64_t a, int64_t b) { return a / b + ((a ^ b) > 0 && a % b); }
constexpr int64_t fdiv(int64_t a, int64_t b) { return a / b - ((a ^ b) < 0 && a % b); }
