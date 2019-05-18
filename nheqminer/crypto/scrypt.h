#ifndef SRC_CRYPTO_SCRYPT_H_
#define SRC_CRYPTO_SCRYPT_H_
#include <cstdio>
#include <stdint.h>

static const int SCRYPT_SCRATCHPAD_SIZE = 131072 + 63;
static const int headerLen = 281; // 212

#ifndef __FreeBSD__
static inline uint32_t le32dec(const void *pp)
{
        const uint8_t *p = (uint8_t const *)pp;
        return ((uint32_t)(p[0]) + ((uint32_t)(p[1]) << 8) +
            ((uint32_t)(p[2]) << 16) + ((uint32_t)(p[3]) << 24));
}

static inline void le32enc(void *pp, uint32_t x)
{
        uint8_t *p = (uint8_t *)pp;
        p[0] = x & 0xff;
        p[1] = (x >> 8) & 0xff;
        p[2] = (x >> 16) & 0xff;
        p[3] = (x >> 24) & 0xff;
}
#endif
void scrypt_1024_1_1_256(const char *input, char *output);
#endif /* SRC_CRYPTO_SCRYPT_H_ */
