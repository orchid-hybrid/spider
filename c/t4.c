#include "runtime.c"
struct scm cons(struct scm, struct scm, struct scm);
struct scm car(struct scm, struct scm);
struct scm cdr(struct scm, struct scm);
struct scm print_each(struct scm, struct scm);
struct scm scm_main(struct scm);
struct scm g2501(struct scm, struct scm, struct scm);
struct scm g2500(struct scm, struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm cons(struct scm env2498, struct scm x, struct scm y) {
    struct scm r0;
    struct scm r1;
    struct scm r2;
    struct scm r3;
    refcount_dec(env2498, 1);
    r2 = y;
    r3 = x;
    r1 = allocate_vector(2);
    scm_vector_insert_bang(r1, r2, 0);
    scm_vector_insert_bang(r1, r3, 1);
    r0 = make_closure(g2499, r1);
    return r0;
}

struct scm car(struct scm env2498, struct scm c) {
    struct scm r4;
    struct scm r5;
    struct scm r9;
    refcount_dec(env2498, 1);
    struct scm clor6;
    clor6 = c;
    r9 = allocate_vector(0);
    r5 = make_closure(g2500, r9);
    scm_fptr clo7;
    struct scm env8;
    clo7 = clor6.val.v->elt[0].val.f;
    env8 = clor6.val.v->elt[1];
    refcount_inc_one(env8);
    r4 = clo7(env8, r5);
    refcount_dec_one(clor6);
    return r4;
}

struct scm cdr(struct scm env2498, struct scm c) {
    struct scm r10;
    struct scm r11;
    struct scm r15;
    refcount_dec(env2498, 1);
    struct scm clor12;
    clor12 = c;
    r15 = allocate_vector(0);
    r11 = make_closure(g2501, r15);
    scm_fptr clo13;
    struct scm env14;
    clo13 = clor12.val.v->elt[0].val.f;
    env14 = clor12.val.v->elt[1];
    refcount_inc_one(env14);
    r10 = clo13(env14, r11);
    refcount_dec_one(clor12);
    return r10;
}

struct scm print_each(struct scm env2498, struct scm list) {
    struct scm r16;
    struct scm r17;
    struct scm r18;
    struct scm r22;
    struct scm r26;
    struct scm r30;
    refcount_dec(env2498, 1);
    refcount_inc(list, 2);
    r17 = list;
    if (scm_extract_truth(r17)) {
        struct scm clor19;
        clor19 = scm_wrap_fptr(scm_print);
        struct scm clor23;
        clor23 = scm_wrap_fptr(car);
        r22 = list;
        scm_fptr clo24;
        struct scm env25;
        clo24 = clor23.val.v->elt[0].val.f;
        env25 = clor23.val.v->elt[1];
        refcount_inc_one(env25);
        r18 = clo24(env25, r22);
        refcount_dec_one(clor23);
        scm_fptr clo20;
        struct scm env21;
        clo20 = clor19.val.v->elt[0].val.f;
        env21 = clor19.val.v->elt[1];
        refcount_inc_one(env21);
        clo20(env21, r18);
        refcount_dec_one(clor19);
        struct scm clor27;
        clor27 = scm_wrap_fptr(print_each);
        struct scm clor31;
        clor31 = scm_wrap_fptr(cdr);
        r30 = list;
        scm_fptr clo32;
        struct scm env33;
        clo32 = clor31.val.v->elt[0].val.f;
        env33 = clor31.val.v->elt[1];
        refcount_inc_one(env33);
        r26 = clo32(env33, r30);
        refcount_dec_one(clor31);
        scm_fptr clo28;
        struct scm env29;
        clo28 = clor27.val.v->elt[0].val.f;
        env29 = clor27.val.v->elt[1];
        refcount_inc_one(env29);
        r16 = clo28(env29, r26);
        refcount_dec_one(clor27);
    } else {
        refcount_dec(list, 2);
        r16 = (struct scm){ .tag = 0, .val.i = 0 };
    }
    return r16;
}

struct scm scm_main(struct scm env2498) {
    struct scm r34;
    struct scm r35;
    struct scm r39;
    struct scm r40;
    struct scm r44;
    struct scm r45;
    struct scm r49;
    struct scm r50;
    refcount_dec(env2498, 1);
    struct scm clor36;
    clor36 = scm_wrap_fptr(print_each);
    struct scm clor41;
    clor41 = scm_wrap_fptr(cons);
    r39 = scm_string_to_vector("Hello");
    struct scm clor46;
    clor46 = scm_wrap_fptr(cons);
    r44 = scm_string_to_vector("World");
    struct scm clor51;
    clor51 = scm_wrap_fptr(cons);
    r49 = scm_string_to_vector("!");
    r50 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo52;
    struct scm env53;
    clo52 = clor51.val.v->elt[0].val.f;
    env53 = clor51.val.v->elt[1];
    refcount_inc_one(env53);
    r45 = clo52(env53, r49, r50);
    refcount_dec_one(clor51);
    scm_fptr clo47;
    struct scm env48;
    clo47 = clor46.val.v->elt[0].val.f;
    env48 = clor46.val.v->elt[1];
    refcount_inc_one(env48);
    r40 = clo47(env48, r44, r45);
    refcount_dec_one(clor46);
    scm_fptr clo42;
    struct scm env43;
    clo42 = clor41.val.v->elt[0].val.f;
    env43 = clor41.val.v->elt[1];
    refcount_inc_one(env43);
    r35 = clo42(env43, r39, r40);
    refcount_dec_one(clor41);
    scm_fptr clo37;
    struct scm env38;
    clo37 = clor36.val.v->elt[0].val.f;
    env38 = clor36.val.v->elt[1];
    refcount_inc_one(env38);
    r34 = clo37(env38, r35);
    refcount_dec_one(clor36);
    return r34;
}

struct scm g2501(struct scm env2498, struct scm x, struct scm y) {
    struct scm r54;
    refcount_dec(env2498, 1);
    refcount_dec(x, 1);
    r54 = y;
    return r54;
}

struct scm g2500(struct scm env2498, struct scm x, struct scm y) {
    struct scm r55;
    refcount_dec(env2498, 1);
    refcount_dec(y, 1);
    r55 = x;
    return r55;
}

struct scm g2499(struct scm env2498, struct scm selector) {
    struct scm r56;
    struct scm r57;
    struct scm r58;
    struct scm r62;
    struct scm r63;
    struct scm r64;
    struct scm r65;
    struct scm r66;
    struct scm r67;
    refcount_inc(env2498, 1);
    struct scm clor59;
    clor59 = selector;
    r62 = (struct scm){ .tag = 0, .val.i = 0 };
    r63 = env2498;
    r64 = (struct scm){ .tag = 0, .val.i = 1 };
    r57 = scm_vector_ref(r62, r63, r64);
    r65 = (struct scm){ .tag = 0, .val.i = 0 };
    r66 = env2498;
    r67 = (struct scm){ .tag = 0, .val.i = 0 };
    r58 = scm_vector_ref(r65, r66, r67);
    scm_fptr clo60;
    struct scm env61;
    clo60 = clor59.val.v->elt[0].val.f;
    env61 = clor59.val.v->elt[1];
    refcount_inc_one(env61);
    r56 = clo60(env61, r57, r58);
    refcount_dec_one(clor59);
    return r56;
}

