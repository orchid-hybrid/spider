#include "runtime.c"
struct scm count_change(struct scm, struct scm);
struct scm or(struct scm, struct scm, struct scm);
struct scm cc(struct scm, struct scm, struct scm);
struct scm first_denomination(struct scm, struct scm);
struct scm scm_main(struct scm);

struct scm count_change(struct scm env2498, struct scm amount) {
    struct scm r0;
    struct scm r1;
    struct scm r2;
    refcount_dec(env2498, 1);
    struct scm clor3;
    clor3 = scm_wrap_fptr(cc);
    r1 = amount;
    r2 = (struct scm){ .tag = 0, .val.i = 5 };
    scm_fptr clo4;
    struct scm env5;
    clo4 = clor3.val.v->elt[0].val.f;
    env5 = clor3.val.v->elt[1];
    refcount_inc_one(env5);
    r0 = clo4(env5, r1, r2);
    refcount_dec_one(clor3);
    return r0;
}

struct scm or(struct scm env2498, struct scm x, struct scm y) {
    struct scm r6;
    struct scm r7;
    refcount_dec(env2498, 1);
    r7 = x;
    if (scm_extract_truth(r7)) {
        refcount_dec(y, 1);
        r6 = (struct scm){ .tag = 0, .val.i = 1 };
    } else {
        r6 = y;
    }
    return r6;
}

struct scm cc(struct scm env2498, struct scm amount, struct scm kinds_of_coins) {
    struct scm r8;
    struct scm r9;
    struct scm r10;
    struct scm r11;
    struct scm r15;
    struct scm r16;
    struct scm r17;
    struct scm r21;
    struct scm r22;
    struct scm r26;
    struct scm r27;
    struct scm r31;
    struct scm r32;
    struct scm r36;
    struct scm r37;
    struct scm r41;
    struct scm r42;
    struct scm r46;
    struct scm r47;
    struct scm r51;
    struct scm r52;
    struct scm r56;
    refcount_dec(env2498, 1);
    refcount_inc(amount, 3);
    refcount_inc(kinds_of_coins, 3);
    struct scm clor12;
    clor12 = scm_wrap_fptr(scm_eq);
    r10 = amount;
    r11 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo13;
    struct scm env14;
    clo13 = clor12.val.v->elt[0].val.f;
    env14 = clor12.val.v->elt[1];
    refcount_inc_one(env14);
    r9 = clo13(env14, r10, r11);
    refcount_dec_one(clor12);
    if (scm_extract_truth(r9)) {
        refcount_dec(amount, 3);
        refcount_dec(kinds_of_coins, 4);
        r8 = (struct scm){ .tag = 0, .val.i = 1 };
    } else {
        struct scm clor18;
        clor18 = scm_wrap_fptr(or);
        struct scm clor23;
        clor23 = scm_wrap_fptr(scm_lt);
        r21 = amount;
        r22 = (struct scm){ .tag = 0, .val.i = 0 };
        scm_fptr clo24;
        struct scm env25;
        clo24 = clor23.val.v->elt[0].val.f;
        env25 = clor23.val.v->elt[1];
        refcount_inc_one(env25);
        r16 = clo24(env25, r21, r22);
        refcount_dec_one(clor23);
        struct scm clor28;
        clor28 = scm_wrap_fptr(scm_eq);
        r26 = kinds_of_coins;
        r27 = (struct scm){ .tag = 0, .val.i = 0 };
        scm_fptr clo29;
        struct scm env30;
        clo29 = clor28.val.v->elt[0].val.f;
        env30 = clor28.val.v->elt[1];
        refcount_inc_one(env30);
        r17 = clo29(env30, r26, r27);
        refcount_dec_one(clor28);
        scm_fptr clo19;
        struct scm env20;
        clo19 = clor18.val.v->elt[0].val.f;
        env20 = clor18.val.v->elt[1];
        refcount_inc_one(env20);
        r15 = clo19(env20, r16, r17);
        refcount_dec_one(clor18);
        if (scm_extract_truth(r15)) {
            refcount_dec(kinds_of_coins, 3);
            refcount_dec(amount, 2);
            r8 = (struct scm){ .tag = 0, .val.i = 0 };
        } else {
            struct scm clor33;
            clor33 = scm_wrap_fptr(scm_plus);
            struct scm clor38;
            clor38 = scm_wrap_fptr(cc);
            r36 = amount;
            struct scm clor43;
            clor43 = scm_wrap_fptr(scm_minus);
            r41 = kinds_of_coins;
            r42 = (struct scm){ .tag = 0, .val.i = 1 };
            scm_fptr clo44;
            struct scm env45;
            clo44 = clor43.val.v->elt[0].val.f;
            env45 = clor43.val.v->elt[1];
            refcount_inc_one(env45);
            r37 = clo44(env45, r41, r42);
            refcount_dec_one(clor43);
            scm_fptr clo39;
            struct scm env40;
            clo39 = clor38.val.v->elt[0].val.f;
            env40 = clor38.val.v->elt[1];
            refcount_inc_one(env40);
            r31 = clo39(env40, r36, r37);
            refcount_dec_one(clor38);
            struct scm clor48;
            clor48 = scm_wrap_fptr(cc);
            struct scm clor53;
            clor53 = scm_wrap_fptr(scm_minus);
            r51 = amount;
            struct scm clor57;
            clor57 = scm_wrap_fptr(first_denomination);
            r56 = kinds_of_coins;
            scm_fptr clo58;
            struct scm env59;
            clo58 = clor57.val.v->elt[0].val.f;
            env59 = clor57.val.v->elt[1];
            refcount_inc_one(env59);
            r52 = clo58(env59, r56);
            refcount_dec_one(clor57);
            scm_fptr clo54;
            struct scm env55;
            clo54 = clor53.val.v->elt[0].val.f;
            env55 = clor53.val.v->elt[1];
            refcount_inc_one(env55);
            r46 = clo54(env55, r51, r52);
            refcount_dec_one(clor53);
            r47 = kinds_of_coins;
            scm_fptr clo49;
            struct scm env50;
            clo49 = clor48.val.v->elt[0].val.f;
            env50 = clor48.val.v->elt[1];
            refcount_inc_one(env50);
            r32 = clo49(env50, r46, r47);
            refcount_dec_one(clor48);
            scm_fptr clo34;
            struct scm env35;
            clo34 = clor33.val.v->elt[0].val.f;
            env35 = clor33.val.v->elt[1];
            refcount_inc_one(env35);
            r8 = clo34(env35, r31, r32);
            refcount_dec_one(clor33);
        }
    }
    return r8;
}

struct scm first_denomination(struct scm env2498, struct scm kinds_of_coins) {
    struct scm r60;
    struct scm r61;
    struct scm r62;
    struct scm r63;
    struct scm r67;
    struct scm r68;
    struct scm r69;
    struct scm r73;
    struct scm r74;
    struct scm r75;
    struct scm r79;
    struct scm r80;
    struct scm r81;
    refcount_dec(env2498, 1);
    refcount_inc(kinds_of_coins, 3);
    struct scm clor64;
    clor64 = scm_wrap_fptr(scm_eq);
    r62 = kinds_of_coins;
    r63 = (struct scm){ .tag = 0, .val.i = 1 };
    scm_fptr clo65;
    struct scm env66;
    clo65 = clor64.val.v->elt[0].val.f;
    env66 = clor64.val.v->elt[1];
    refcount_inc_one(env66);
    r61 = clo65(env66, r62, r63);
    refcount_dec_one(clor64);
    if (scm_extract_truth(r61)) {
        refcount_dec(kinds_of_coins, 3);
        r60 = (struct scm){ .tag = 0, .val.i = 1 };
    } else {
        struct scm clor70;
        clor70 = scm_wrap_fptr(scm_eq);
        r68 = kinds_of_coins;
        r69 = (struct scm){ .tag = 0, .val.i = 2 };
        scm_fptr clo71;
        struct scm env72;
        clo71 = clor70.val.v->elt[0].val.f;
        env72 = clor70.val.v->elt[1];
        refcount_inc_one(env72);
        r67 = clo71(env72, r68, r69);
        refcount_dec_one(clor70);
        if (scm_extract_truth(r67)) {
            refcount_dec(kinds_of_coins, 2);
            r60 = (struct scm){ .tag = 0, .val.i = 5 };
        } else {
            struct scm clor76;
            clor76 = scm_wrap_fptr(scm_eq);
            r74 = kinds_of_coins;
            r75 = (struct scm){ .tag = 0, .val.i = 3 };
            scm_fptr clo77;
            struct scm env78;
            clo77 = clor76.val.v->elt[0].val.f;
            env78 = clor76.val.v->elt[1];
            refcount_inc_one(env78);
            r73 = clo77(env78, r74, r75);
            refcount_dec_one(clor76);
            if (scm_extract_truth(r73)) {
                refcount_dec(kinds_of_coins, 1);
                r60 = (struct scm){ .tag = 0, .val.i = 10 };
            } else {
                struct scm clor82;
                clor82 = scm_wrap_fptr(scm_eq);
                r80 = kinds_of_coins;
                r81 = (struct scm){ .tag = 0, .val.i = 4 };
                scm_fptr clo83;
                struct scm env84;
                clo83 = clor82.val.v->elt[0].val.f;
                env84 = clor82.val.v->elt[1];
                refcount_inc_one(env84);
                r79 = clo83(env84, r80, r81);
                refcount_dec_one(clor82);
                if (scm_extract_truth(r79)) {
                    r60 = (struct scm){ .tag = 0, .val.i = 25 };
                } else {
                    r60 = (struct scm){ .tag = 0, .val.i = 50 };
                }
            }
        }
    }
    return r60;
}

struct scm scm_main(struct scm env2498) {
    struct scm r85;
    struct scm r86;
    struct scm r90;
    refcount_dec(env2498, 1);
    struct scm clor87;
    clor87 = scm_wrap_fptr(scm_print);
    struct scm clor91;
    clor91 = scm_wrap_fptr(count_change);
    r90 = (struct scm){ .tag = 0, .val.i = 100 };
    scm_fptr clo92;
    struct scm env93;
    clo92 = clor91.val.v->elt[0].val.f;
    env93 = clor91.val.v->elt[1];
    refcount_inc_one(env93);
    r86 = clo92(env93, r90);
    refcount_dec_one(clor91);
    scm_fptr clo88;
    struct scm env89;
    clo88 = clor87.val.v->elt[0].val.f;
    env89 = clor87.val.v->elt[1];
    refcount_inc_one(env89);
    r85 = clo88(env89, r86);
    refcount_dec_one(clor87);
    return r85;
}

