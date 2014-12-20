#include "runtime.c"
struct scm bar(struct scm);
struct scm foo(struct scm, struct scm);
struct scm scm_main(struct scm);
struct scm g2500(struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm bar(struct scm env2498) {
    struct scm r0;
    struct scm r1;
    struct scm r2;
    struct scm r6;
    struct scm clor3;
    clor3 = scm_wrap_fptr(scm_make_vector);
    r1 = (struct scm){ .tag = 0, .val.i = 2 };
    r6 = allocate_vector(0);
    r2 = make_closure(g2499, r6);
    scm_fptr clo4;
    struct scm env5;
    clo4 = clor3.val.v->elt[0].val.f;
    env5 = clor3.val.v->elt[1];
    r0 = clo4(env5, r1, r2);
    refcount_dec_one(clor3);
    return r0;
}

struct scm foo(struct scm env2498, struct scm v) {
    struct scm r7;
    struct scm r8;
    struct scm r9;
    struct scm r13;
    struct scm r14;
    struct scm clor10;
    clor10 = scm_wrap_fptr(scm_make_vector);
    r8 = (struct scm){ .tag = 0, .val.i = 2 };
    r14 = v;
    r13 = allocate_vector(1);
    scm_vector_insert_bang(r13, r14, 0);
    r9 = make_closure(g2500, r13);
    scm_fptr clo11;
    struct scm env12;
    clo11 = clor10.val.v->elt[0].val.f;
    env12 = clor10.val.v->elt[1];
    r7 = clo11(env12, r8, r9);
    refcount_dec_one(clor10);
    return r7;
}

struct scm scm_main(struct scm env2498) {
    struct scm r15;
    struct scm r16;
    struct scm clor17;
    clor17 = scm_wrap_fptr(foo);
    struct scm clor20;
    clor20 = scm_wrap_fptr(bar);
    scm_fptr clo21;
    struct scm env22;
    clo21 = clor20.val.v->elt[0].val.f;
    env22 = clor20.val.v->elt[1];
    r16 = clo21(env22);
    refcount_dec_one(clor20);
    scm_fptr clo18;
    struct scm env19;
    clo18 = clor17.val.v->elt[0].val.f;
    env19 = clor17.val.v->elt[1];
    r15 = clo18(env19, r16);
    refcount_dec_one(clor17);
    return r15;
}

struct scm g2500(struct scm env2498, struct scm i) {
    struct scm r23;
    struct scm r24;
    struct scm r25;
    struct scm r29;
    struct scm r30;
    struct scm r31;
    struct scm r32;
    struct scm r33;
    struct scm clor26;
    clor26 = scm_wrap_fptr(scm_vector_ref);
    r29 = (struct scm){ .tag = 0, .val.i = 0 };
    r30 = env2498;
    r31 = (struct scm){ .tag = 0, .val.i = 0 };
    r24 = scm_vector_ref(r29, r30, r31);
    struct scm clor34;
    clor34 = scm_wrap_fptr(scm_minus);
    r32 = (struct scm){ .tag = 0, .val.i = 1 };
    r33 = i;
    scm_fptr clo35;
    struct scm env36;
    clo35 = clor34.val.v->elt[0].val.f;
    env36 = clor34.val.v->elt[1];
    r25 = clo35(env36, r32, r33);
    refcount_dec_one(clor34);
    scm_fptr clo27;
    struct scm env28;
    clo27 = clor26.val.v->elt[0].val.f;
    env28 = clor26.val.v->elt[1];
    r23 = clo27(env28, r24, r25);
    refcount_dec_one(clor26);
    return r23;
}

struct scm g2499(struct scm env2498, struct scm i) {
    struct scm r37;
    struct scm r38;
    struct scm r39;
    struct scm r40;
    struct scm clor41;
    clor41 = scm_wrap_fptr(scm_eq);
    r39 = i;
    r40 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo42;
    struct scm env43;
    clo42 = clor41.val.v->elt[0].val.f;
    env43 = clor41.val.v->elt[1];
    r38 = clo42(env43, r39, r40);
    refcount_dec_one(clor41);
    if (scm_extract_truth(r38)) {
        r37 = (struct scm){ .tag = 0, .val.i = 105 };
    } else {
        r37 = (struct scm){ .tag = 0, .val.i = 104 };
    }
    return r37;
}

