#include "runtime.c"
struct scm foo(struct scm);
struct scm scm_main(struct scm);
struct scm g2499(struct scm, struct scm);

struct scm foo(struct scm env2498) {
    struct scm r0;
    struct scm r1;
    struct scm r2;
    struct scm r6;
    refcount_dec(env2498, 1);
    struct scm clor3;
    clor3 = scm_wrap_fptr(scm_make_vector);
    r1 = (struct scm){ .tag = 0, .val.i = 2 };
    r6 = allocate_vector(0);
    r2 = make_closure(g2499, r6);
    scm_fptr clo4;
    struct scm env5;
    clo4 = clor3.val.v->elt[0].val.f;
    env5 = clor3.val.v->elt[1];
    refcount_inc_one(env5);
    r0 = clo4(env5, r1, r2);
    refcount_dec_one(clor3);
    return r0;
}

struct scm scm_main(struct scm env2498) {
    struct scm r7;
    refcount_dec(env2498, 1);
    struct scm clor8;
    clor8 = scm_wrap_fptr(foo);
    scm_fptr clo9;
    struct scm env10;
    clo9 = clor8.val.v->elt[0].val.f;
    env10 = clor8.val.v->elt[1];
    refcount_inc_one(env10);
    r7 = clo9(env10);
    refcount_dec_one(clor8);
    return r7;
}

struct scm g2499(struct scm env2498, struct scm i) {
    struct scm r11;
    struct scm r12;
    struct scm r13;
    struct scm r14;
    refcount_dec(env2498, 1);
    struct scm clor15;
    clor15 = scm_wrap_fptr(scm_eq);
    r13 = i;
    r14 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo16;
    struct scm env17;
    clo16 = clor15.val.v->elt[0].val.f;
    env17 = clor15.val.v->elt[1];
    refcount_inc_one(env17);
    r12 = clo16(env17, r13, r14);
    refcount_dec_one(clor15);
    if (scm_extract_truth(r12)) {
        r11 = (struct scm){ .tag = 0, .val.i = 105 };
    } else {
        r11 = (struct scm){ .tag = 0, .val.i = 104 };
    }
    return r11;
}

