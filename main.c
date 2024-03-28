#include "headers.h"

float pi;

static void dft(const float* in, float complex* out, const size_t n) {
    for (size_t f = 0; f < n; ++f) {
        out[f] = 0;
        for (size_t i = 0; i < n; ++i) {
            float t = (float)i/n;
            out[f] += in[i] * cexp(2*I*pi*f*t);
        }
    }
}

static void fft_(float* in, size_t stride, float complex* out, size_t n) {
    if (n == 1) {
        out[0] = in[0];
        return;
    }
    fft_(in, stride*2, out, n/2);
    fft_(in + stride, stride*2, out + n/2, n/2);
    for (size_t k = 0; k < n/2; ++k) {
        float t = (float)k/n;
        float complex v = cexp(2*I*pi*t) * out[k + n/2];
        float complex e = out[k];
        out[k] = e + v;
        out[k + n/2] = e - v;
    }

}
void fft(float* in, float complex* out, size_t n) {
    fft_(in, 1, out, n);
}

int main(void) {
    const size_t n = 8;
    float in[n];
    float complex out[n];
    pi = atan2f(1, 1) * 4;

    for (size_t i = 0; i < n; ++i) {
        float t = (float)i / n;
        in[i] = sinf(2*pi*t*1) + sinf(2*pi*t*2) + cos(2*pi*t*0);
    }

    fft(in, out, n);

    for (size_t i = 0; i < n; ++i) {
        printf("%zu. ", i);
        printf("%d %d\n", (int)crealf(out[i]), (int)cimagf(out[i]));
    }
}