#ifndef QEMU_BITFLIP_H
#define QEMU_BITFLIP_H

enum bitflip_type {REG, RIP, EFLAGS, MEM};

struct bitflip {
    enum bitflip_type type;
    uint64_t pc,
            mask;
    int      itr,
            itrCounter;
    union {
        int     reg;
        uint64_t mem_ptr;
    };
};

extern struct bitflip* bitflips;
extern int bitflips_size;

#endif //QEMU_BITFLIP_H