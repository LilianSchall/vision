#ifndef MATHS_HXX
#define MATHS_HXX

template<typename T>
concept Comparable = requires(T a, T b){
    {a < b} -> std::convertible_to<bool>;
    {a > b} -> std::convertible_to<bool>;
    {a == b} -> std::convertible_to<bool>;
};

template<Comparable T>
inline T& max2(T &a, T &b) {
    return a > b ? a : b;
}

template<Comparable T>
inline T& min2(T &a, T &b) {
    return a > b ? b : a;
}

#endif // !MATHS_HXX