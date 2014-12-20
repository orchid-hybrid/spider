#include "runtime.c"
struct scm scm_main(struct scm);
struct scm one(struct scm);
struct scm two(struct scm);
struct scm three(struct scm);
struct scm add(struct scm, struct scm, struct scm);
struct scm mul(struct scm, struct scm, struct scm);
struct scm g2505(struct scm, struct scm, struct scm);
struct scm g2504(struct scm, struct scm);
struct scm g2503(struct scm, struct scm, struct scm);
struct scm g2502(struct scm, struct scm, struct scm);
struct scm g2501(struct scm, struct scm, struct scm);
struct scm g2500(struct scm, struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm scm_main(struct scm env2498) {
    struct scm r0;
    struct scm r1;
    struct scm r2;
    struct scm r6;
    struct scm r7;
    struct scm r11;
    struct scm r12;
    struct scm r25;
    refcount_dec(env2498, 1);
    struct scm clor3;
    struct scm clor8;
    clor8 = scm_wrap_fptr(mul);
    struct scm clor13;
    clor13 = scm_wrap_fptr(add);
    struct scm clor16;
    clor16 = scm_wrap_fptr(three);
    scm_fptr clo17;
    struct scm env18;
    clo17 = clor16.val.v->elt[0].val.f;
    env18 = clor16.val.v->elt[1];
    refcount_inc_one(env18);
    r11 = clo17(env18);
    refcount_dec_one(clor16);
    struct scm clor19;
    clor19 = scm_wrap_fptr(two);
    scm_fptr clo20;
    struct scm env21;
    clo20 = clor19.val.v->elt[0].val.f;
    env21 = clor19.val.v->elt[1];
    refcount_inc_one(env21);
    r12 = clo20(env21);
    refcount_dec_one(clor19);
    scm_fptr clo14;
    struct scm env15;
    clo14 = clor13.val.v->elt[0].val.f;
    env15 = clor13.val.v->elt[1];
    refcount_inc_one(env15);
    r6 = clo14(env15, r11, r12);
    refcount_dec_one(clor13);
    struct scm clor22;
    clor22 = scm_wrap_fptr(three);
    scm_fptr clo23;
    struct scm env24;
    clo23 = clor22.val.v->elt[0].val.f;
    env24 = clor22.val.v->elt[1];
    refcount_inc_one(env24);
    r7 = clo23(env24);
    refcount_dec_one(clor22);
    scm_fptr clo9;
    struct scm env10;
    clo9 = clor8.val.v->elt[0].val.f;
    env10 = clor8.val.v->elt[1];
    refcount_inc_one(env10);
    clor3 = clo9(env10, r6, r7);
    refcount_dec_one(clor8);
    r1 = (struct scm){ .tag = 0, .val.i = 0 };
    r25 = allocate_vector(0);
    r2 = make_closure(g2499, r25);
    scm_fptr clo4;
    struct scm env5;
    clo4 = clor3.val.v->elt[0].val.f;
    env5 = clor3.val.v->elt[1];
    refcount_inc_one(env5);
    r0 = clo4(env5, r1, r2);
    refcount_dec_one(clor3);
    return r0;
}

struct scm one(struct scm env2498) {
    struct scm r26;
    struct scm r27;
    refcount_dec(env2498, 1);
    r27 = allocate_vector(0);
    r26 = make_closure(g2500, r27);
    return r26;
}

struct scm two(struct scm env2498) {
    struct scm r28;
    struct scm r29;
    refcount_dec(env2498, 1);
    r29 = allocate_vector(0);
    r28 = make_closure(g2501, r29);
    return r28;
}

struct scm three(struct scm env2498) {
    struct scm r30;
    struct scm r31;
    refcount_dec(env2498, 1);
    r31 = allocate_vector(0);
    r30 = make_closure(g2502, r31);
    return r30;
}

struct scm add(struct scm env2498, struct scm x, struct scm y) {
    struct scm r32;
    struct scm r33;
    struct scm r34;
    struct scm r35;
    refcount_dec(env2498, 1);
    r34 = x;
    r35 = y;
    r33 = allocate_vector(2);
    scm_vector_insert_bang(r33, r34, 0);
    scm_vector_insert_bang(r33, r35, 1);
    r32 = make_closure(g2503, r33);
    return r32;
}

struct scm mul(struct scm env2498, struct scm x, struct scm y) {
    struct scm r36;
    struct scm r37;
    struct scm r38;
    struct scm r39;
    refcount_dec(env2498, 1);
    r38 = y;
    r39 = x;
    r37 = allocate_vector(2);
    scm_vector_insert_bang(r37, r38, 0);
    scm_vector_insert_bang(r37, r39, 1);
    r36 = make_closure(g2505, r37);
    return r36;
}

struct scm g2505(struct scm env2498, struct scm z, struct scm s) {
    struct scm r40;
    struct scm r41;
    struct scm r42;
    struct scm r46;
    struct scm r47;
    struct scm r48;
    struct scm r49;
    struct scm r50;
    struct scm r51;
    struct scm r52;
    struct scm r53;
    struct scm r54;
    refcount_inc(env2498, 1);
    struct scm clor43;
    r46 = (struct scm){ .tag = 0, .val.i = 0 };
    r47 = env2498;
    r48 = (struct scm){ .tag = 0, .val.i = 1 };
    clor43 = scm_vector_ref(r46, r47, r48);
    r41 = z;
    r50 = s;
    r52 = (struct scm){ .tag = 0, .val.i = 0 };
    r53 = env2498;
    r54 = (struct scm){ .tag = 0, .val.i = 0 };
    r51 = scm_vector_ref(r52, r53, r54);
    r49 = allocate_vector(2);
    scm_vector_insert_bang(r49, r50, 0);
    scm_vector_insert_bang(r49, r51, 1);
    r42 = make_closure(g2504, r49);
    scm_fptr clo44;
    struct scm env45;
    clo44 = clor43.val.v->elt[0].val.f;
    env45 = clor43.val.v->elt[1];
    refcount_inc_one(env45);
    r40 = clo44(env45, r41, r42);
    refcount_dec_one(clor43);
    return r40;
}

struct scm g2504(struct scm env2498, struct scm z) {
    struct scm r55;
    struct scm r56;
    struct scm r57;
    struct scm r61;
    struct scm r62;
    struct scm r63;
    struct scm r64;
    struct scm r65;
    struct scm r66;
    refcount_inc(env2498, 1);
    struct scm clor58;
    r61 = (struct scm){ .tag = 0, .val.i = 0 };
    r62 = env2498;
    r63 = (struct scm){ .tag = 0, .val.i = 1 };
    clor58 = scm_vector_ref(r61, r62, r63);
    r56 = z;
    r64 = (struct scm){ .tag = 0, .val.i = 0 };
    r65 = env2498;
    r66 = (struct scm){ .tag = 0, .val.i = 0 };
    r57 = scm_vector_ref(r64, r65, r66);
    scm_fptr clo59;
    struct scm env60;
    clo59 = clor58.val.v->elt[0].val.f;
    env60 = clor58.val.v->elt[1];
    refcount_inc_one(env60);
    r55 = clo59(env60, r56, r57);
    refcount_dec_one(clor58);
    return r55;
}

struct scm g2503(struct scm env2498, struct scm z, struct scm s) {
    struct scm r67;
    struct scm r68;
    struct scm r69;
    struct scm r73;
    struct scm r74;
    struct scm r75;
    struct scm r76;
    struct scm r77;
    struct scm r81;
    struct scm r82;
    struct scm r83;
    refcount_inc(env2498, 1);
    refcount_inc(s, 1);
    struct scm clor70;
    r73 = (struct scm){ .tag = 0, .val.i = 0 };
    r74 = env2498;
    r75 = (struct scm){ .tag = 0, .val.i = 1 };
    clor70 = scm_vector_ref(r73, r74, r75);
    struct scm clor78;
    r81 = (struct scm){ .tag = 0, .val.i = 0 };
    r82 = env2498;
    r83 = (struct scm){ .tag = 0, .val.i = 0 };
    clor78 = scm_vector_ref(r81, r82, r83);
    r76 = z;
    r77 = s;
    scm_fptr clo79;
    struct scm env80;
    clo79 = clor78.val.v->elt[0].val.f;
    env80 = clor78.val.v->elt[1];
    refcount_inc_one(env80);
    r68 = clo79(env80, r76, r77);
    refcount_dec_one(clor78);
    r69 = s;
    scm_fptr clo71;
    struct scm env72;
    clo71 = clor70.val.v->elt[0].val.f;
    env72 = clor70.val.v->elt[1];
    refcount_inc_one(env72);
    r67 = clo71(env72, r68, r69);
    refcount_dec_one(clor70);
    return r67;
}

struct scm g2502(struct scm env2498, struct scm z, struct scm s) {
    struct scm r84;
    struct scm r85;
    struct scm r89;
    struct scm r93;
    refcount_dec(env2498, 1);
    refcount_inc(s, 2);
    struct scm clor86;
    clor86 = s;
    struct scm clor90;
    clor90 = s;
    struct scm clor94;
    clor94 = s;
    r93 = z;
    scm_fptr clo95;
    struct scm env96;
    clo95 = clor94.val.v->elt[0].val.f;
    env96 = clor94.val.v->elt[1];
    refcount_inc_one(env96);
    r89 = clo95(env96, r93);
    refcount_dec_one(clor94);
    scm_fptr clo91;
    struct scm env92;
    clo91 = clor90.val.v->elt[0].val.f;
    env92 = clor90.val.v->elt[1];
    refcount_inc_one(env92);
    r85 = clo91(env92, r89);
    refcount_dec_one(clor90);
    scm_fptr clo87;
    struct scm env88;
    clo87 = clor86.val.v->elt[0].val.f;
    env88 = clor86.val.v->elt[1];
    refcount_inc_one(env88);
    r84 = clo87(env88, r85);
    refcount_dec_one(clor86);
    return r84;
}

struct scm g2501(struct scm env2498, struct scm z, struct scm s) {
    struct scm r97;
    struct scm r98;
    struct scm r102;
    refcount_dec(env2498, 1);
    refcount_inc(s, 1);
    struct scm clor99;
    clor99 = s;
    struct scm clor103;
    clor103 = s;
    r102 = z;
    scm_fptr clo104;
    struct scm env105;
    clo104 = clor103.val.v->elt[0].val.f;
    env105 = clor103.val.v->elt[1];
    refcount_inc_one(env105);
    r98 = clo104(env105, r102);
    refcount_dec_one(clor103);
    scm_fptr clo100;
    struct scm env101;
    clo100 = clor99.val.v->elt[0].val.f;
    env101 = clor99.val.v->elt[1];
    refcount_inc_one(env101);
    r97 = clo100(env101, r98);
    refcount_dec_one(clor99);
    return r97;
}

struct scm g2500(struct scm env2498, struct scm z, struct scm s) {
    struct scm r106;
    struct scm r107;
    refcount_dec(env2498, 1);
    struct scm clor108;
    clor108 = s;
    r107 = z;
    scm_fptr clo109;
    struct scm env110;
    clo109 = clor108.val.v->elt[0].val.f;
    env110 = clor108.val.v->elt[1];
    refcount_inc_one(env110);
    r106 = clo109(env110, r107);
    refcount_dec_one(clor108);
    return r106;
}

struct scm g2499(struct scm env2498, struct scm i) {
    struct scm r111;
    struct scm r112;
    refcount_dec(env2498, 1);
    refcount_dec(i, 1);
    struct scm clor113;
    clor113 = scm_wrap_fptr(scm_print);
    r112 = scm_string_to_vector("i");
    scm_fptr clo114;
    struct scm env115;
    clo114 = clor113.val.v->elt[0].val.f;
    env115 = clor113.val.v->elt[1];
    refcount_inc_one(env115);
    r111 = clo114(env115, r112);
    refcount_dec_one(clor113);
    return r111;
}

