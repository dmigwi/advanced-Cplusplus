int main() {
    // Address 0 is reserved for the null ptr therefore the code below is
    // attempting to dereference a null pointer and then assign it the value of 
    // zero.
    *(volatile char*)0 = 0;

    // *reinterpret_cast<volatile char*>(0) = 0; // invalid conversion.

    return 0;
}