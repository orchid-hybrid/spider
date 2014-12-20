#include "runtime.c"
struct scm scm_main(struct scm);
struct scm church_num(struct scm, struct scm);
struct scm begin(struct scm, struct scm, struct scm);
struct scm num_church(struct scm, struct scm);
struct scm zero(struct scm);
struct scm one(struct scm);
struct scm two(struct scm);
struct scm three(struct scm);
struct scm add(struct scm, struct scm, struct scm);
struct scm mul(struct scm, struct scm, struct scm);
struct scm g2508(struct scm, struct scm, struct scm);
struct scm g2507(struct scm, struct scm);
struct scm g2506(struct scm, struct scm, struct scm);
struct scm g2505(struct scm, struct scm, struct scm);
struct scm g2504(struct scm, struct scm, struct scm);
struct scm g2503(struct scm, struct scm, struct scm);
struct scm g2502(struct scm, struct scm, struct scm);
struct scm g2501(struct scm, struct scm, struct scm, struct scm);
struct scm g2500(struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm scm_main(struct scm env2498) {
    struct scm r0;
    struct scm r1;
    struct scm r5;
    struct scm r9;
    struct scm r10;
    struct scm r14;
    struct scm r15;
    struct scm r25;
    refcount_dec(env2498, 1);
    struct scm clor2;
    clor2 = scm_wrap_fptr(scm_print);
    struct scm clor6;
    clor6 = scm_wrap_fptr(church_num);
    struct scm clor11;
    clor11 = scm_wrap_fptr(mul);
    struct scm clor16;
    clor16 = scm_wrap_fptr(add);
    struct scm clor19;
    clor19 = scm_wrap_fptr(three);
    scm_fptr clo20;
    struct scm env21;
    clo20 = clor19.val.v->elt[0].val.f;
    env21 = clor19.val.v->elt[1];
    refcount_inc_one(env21);
    r14 = clo20(env21);
    refcount_dec_one(clor19);
    struct scm clor22;
    clor22 = scm_wrap_fptr(two);
    scm_fptr clo23;
    struct scm env24;
    clo23 = clor22.val.v->elt[0].val.f;
    env24 = clor22.val.v->elt[1];
    refcount_inc_one(env24);
    r15 = clo23(env24);
    refcount_dec_one(clor22);
    scm_fptr clo17;
    struct scm env18;
    clo17 = clor16.val.v->elt[0].val.f;
    env18 = clor16.val.v->elt[1];
    refcount_inc_one(env18);
    r9 = clo17(env18, r14, r15);
    refcount_dec_one(clor16);
    struct scm clor26;
    clor26 = scm_wrap_fptr(num_church);
    r25 = (struct scm){ .tag = 0, .val.i = 5 };
    scm_fptr clo27;
    struct scm env28;
    clo27 = clor26.val.v->elt[0].val.f;
    env28 = clor26.val.v->elt[1];
    refcount_inc_one(env28);
    r10 = clo27(env28, r25);
    refcount_dec_one(clor26);
    scm_fptr clo12;
    struct scm env13;
    clo12 = clor11.val.v->elt[0].val.f;
    env13 = clor11.val.v->elt[1];
    refcount_inc_one(env13);
    r5 = clo12(env13, r9, r10);
    refcount_dec_one(clor11);
    scm_fptr clo7;
    struct scm env8;
    clo7 = clor6.val.v->elt[0].val.f;
    env8 = clor6.val.v->elt[1];
    refcount_inc_one(env8);
    r1 = clo7(env8, r5);
    refcount_dec_one(clor6);
    scm_fptr clo3;
    struct scm env4;
    clo3 = clor2.val.v->elt[0].val.f;
    env4 = clor2.val.v->elt[1];
    refcount_inc_one(env4);
    r0 = clo3(env4, r1);
    refcount_dec_one(clor2);
    return r0;
}

struct scm church_num(struct scm env2498, struct scm n) {
    struct scm r29;
    struct scm r30;
    struct scm r31;
    struct scm r35;
    refcount_dec(env2498, 1);
    struct scm clor32;
    clor32 = n;
    r30 = (struct scm){ .tag = 0, .val.i = 0 };
    r35 = allocate_vector(0);
    r31 = make_closure(g2499, r35);
    scm_fptr clo33;
    struct scm env34;
    clo33 = clor32.val.v->elt[0].val.f;
    env34 = clor32.val.v->elt[1];
    refcount_inc_one(env34);
    r29 = clo33(env34, r30, r31);
    refcount_dec_one(clor32);
    return r29;
}

struct scm begin(struct scm env2498, struct scm a, struct scm b) {
    struct scm r36;
    refcount_dec(env2498, 1);
    refcount_dec(a, 1);
    r36 = b;
    return r36;
}

struct scm num_church(struct scm env2498, struct scm n) {
    struct scm r37;
    struct scm r38;
    struct scm r42;
    struct scm r43;
    struct scm r44;
    refcount_dec(env2498, 1);
    struct scm clor39;
    r42 = allocate_vector(0);
    clor39 = make_closure(g2500, r42);
    r44 = n;
    r43 = allocate_vector(1);
    scm_vector_insert_bang(r43, r44, 0);
    r38 = make_closure(g2501, r43);
    scm_fptr clo40;
    struct scm env41;
    clo40 = clor39.val.v->elt[0].val.f;
    env41 = clor39.val.v->elt[1];
    refcount_inc_one(env41);
    r37 = clo40(env41, r38);
    refcount_dec_one(clor39);
    return r37;
}

struct scm zero(struct scm env2498) {
    struct scm r45;
    struct scm r46;
    refcount_dec(env2498, 1);
    r46 = allocate_vector(0);
    r45 = make_closure(g2502, r46);
    return r45;
}

struct scm one(struct scm env2498) {
    struct scm r47;
    struct scm r48;
    refcount_dec(env2498, 1);
    r48 = allocate_vector(0);
    r47 = make_closure(g2503, r48);
    return r47;
}

struct scm two(struct scm env2498) {
    struct scm r49;
    struct scm r50;
    refcount_dec(env2498, 1);
    r50 = allocate_vector(0);
    r49 = make_closure(g2504, r50);
    return r49;
}

struct scm three(struct scm env2498) {
    struct scm r51;
    struct scm r52;
    refcount_dec(env2498, 1);
    r52 = allocate_vector(0);
    r51 = make_closure(g2505, r52);
    return r51;
}

struct scm add(struct scm env2498, struct scm x, struct scm y) {
    struct scm r53;
    struct scm r54;
    struct scm r55;
    struct scm r56;
    refcount_dec(env2498, 1);
    r55 = x;
    r56 = y;
    r54 = allocate_vector(2);
    scm_vector_insert_bang(r54, r55, 0);
    scm_vector_insert_bang(r54, r56, 1);
    r53 = make_closure(g2506, r54);
    return r53;
}

struct scm mul(struct scm env2498, struct scm x, struct scm y) {
    struct scm r57;
    struct scm r58;
    struct scm r59;
    struct scm r60;
    refcount_dec(env2498, 1);
    r59 = y;
    r60 = x;
    r58 = allocate_vector(2);
    scm_vector_insert_bang(r58, r59, 0);
    scm_vector_insert_bang(r58, r60, 1);
    r57 = make_closure(g2508, r58);
    return r57;
}

struct scm g2508(struct scm env2498, struct scm z, struct scm s) {
    struct scm r61;
    struct scm r62;
    struct scm r63;
    struct scm r67;
    struct scm r68;
    struct scm r69;
    struct scm r70;
    struct scm r71;
    struct scm r72;
    struct scm r73;
    struct scm r74;
    struct scm r75;
    refcount_inc(env2498, 1);
    struct scm clor64;
    r67 = (struct scm){ .tag = 0, .val.i = 0 };
    r68 = env2498;
    r69 = (struct scm){ .tag = 0, .val.i = 1 };
    clor64 = scm_vector_ref(r67, r68, r69);
    r62 = z;
    r71 = s;
    r73 = (struct scm){ .tag = 0, .val.i = 0 };
    r74 = env2498;
    r75 = (struct scm){ .tag = 0, .val.i = 0 };
    r72 = scm_vector_ref(r73, r74, r75);
    r70 = allocate_vector(2);
    scm_vector_insert_bang(r70, r71, 0);
    scm_vector_insert_bang(r70, r72, 1);
    r63 = make_closure(g2507, r70);
    scm_fptr clo65;
    struct scm env66;
    clo65 = clor64.val.v->elt[0].val.f;
    env66 = clor64.val.v->elt[1];
    refcount_inc_one(env66);
    r61 = clo65(env66, r62, r63);
    refcount_dec_one(clor64);
    return r61;
}

struct scm g2507(struct scm env2498, struct scm z) {
    struct scm r76;
    struct scm r77;
    struct scm r78;
    struct scm r82;
    struct scm r83;
    struct scm r84;
    struct scm r85;
    struct scm r86;
    struct scm r87;
    refcount_inc(env2498, 1);
    struct scm clor79;
    r82 = (struct scm){ .tag = 0, .val.i = 0 };
    r83 = env2498;
    r84 = (struct scm){ .tag = 0, .val.i = 1 };
    clor79 = scm_vector_ref(r82, r83, r84);
    r77 = z;
    r85 = (struct scm){ .tag = 0, .val.i = 0 };
    r86 = env2498;
    r87 = (struct scm){ .tag = 0, .val.i = 0 };
    r78 = scm_vector_ref(r85, r86, r87);
    scm_fptr clo80;
    struct scm env81;
    clo80 = clor79.val.v->elt[0].val.f;
    env81 = clor79.val.v->elt[1];
    refcount_inc_one(env81);
    r76 = clo80(env81, r77, r78);
    refcount_dec_one(clor79);
    return r76;
}

struct scm g2506(struct scm env2498, struct scm z, struct scm s) {
    struct scm r88;
    struct scm r89;
    struct scm r90;
    struct scm r94;
    struct scm r95;
    struct scm r96;
    struct scm r97;
    struct scm r98;
    struct scm r102;
    struct scm r103;
    struct scm r104;
    refcount_inc(env2498, 1);
    refcount_inc(s, 1);
    struct scm clor91;
    r94 = (struct scm){ .tag = 0, .val.i = 0 };
    r95 = env2498;
    r96 = (struct scm){ .tag = 0, .val.i = 1 };
    clor91 = scm_vector_ref(r94, r95, r96);
    struct scm clor99;
    r102 = (struct scm){ .tag = 0, .val.i = 0 };
    r103 = env2498;
    r104 = (struct scm){ .tag = 0, .val.i = 0 };
    clor99 = scm_vector_ref(r102, r103, r104);
    r97 = z;
    r98 = s;
    scm_fptr clo100;
    struct scm env101;
    clo100 = clor99.val.v->elt[0].val.f;
    env101 = clor99.val.v->elt[1];
    refcount_inc_one(env101);
    r89 = clo100(env101, r97, r98);
    refcount_dec_one(clor99);
    r90 = s;
    scm_fptr clo92;
    struct scm env93;
    clo92 = clor91.val.v->elt[0].val.f;
    env93 = clor91.val.v->elt[1];
    refcount_inc_one(env93);
    r88 = clo92(env93, r89, r90);
    refcount_dec_one(clor91);
    return r88;
}

struct scm g2505(struct scm env2498, struct scm z, struct scm s) {
    struct scm r105;
    struct scm r106;
    struct scm r110;
    struct scm r114;
    refcount_dec(env2498, 1);
    refcount_inc(s, 2);
    struct scm clor107;
    clor107 = s;
    struct scm clor111;
    clor111 = s;
    struct scm clor115;
    clor115 = s;
    r114 = z;
    scm_fptr clo116;
    struct scm env117;
    clo116 = clor115.val.v->elt[0].val.f;
    env117 = clor115.val.v->elt[1];
    refcount_inc_one(env117);
    r110 = clo116(env117, r114);
    refcount_dec_one(clor115);
    scm_fptr clo112;
    struct scm env113;
    clo112 = clor111.val.v->elt[0].val.f;
    env113 = clor111.val.v->elt[1];
    refcount_inc_one(env113);
    r106 = clo112(env113, r110);
    refcount_dec_one(clor111);
    scm_fptr clo108;
    struct scm env109;
    clo108 = clor107.val.v->elt[0].val.f;
    env109 = clor107.val.v->elt[1];
    refcount_inc_one(env109);
    r105 = clo108(env109, r106);
    refcount_dec_one(clor107);
    return r105;
}

struct scm g2504(struct scm env2498, struct scm z, struct scm s) {
    struct scm r118;
    struct scm r119;
    struct scm r123;
    refcount_dec(env2498, 1);
    refcount_inc(s, 1);
    struct scm clor120;
    clor120 = s;
    struct scm clor124;
    clor124 = s;
    r123 = z;
    scm_fptr clo125;
    struct scm env126;
    clo125 = clor124.val.v->elt[0].val.f;
    env126 = clor124.val.v->elt[1];
    refcount_inc_one(env126);
    r119 = clo125(env126, r123);
    refcount_dec_one(clor124);
    scm_fptr clo121;
    struct scm env122;
    clo121 = clor120.val.v->elt[0].val.f;
    env122 = clor120.val.v->elt[1];
    refcount_inc_one(env122);
    r118 = clo121(env122, r119);
    refcount_dec_one(clor120);
    return r118;
}

struct scm g2503(struct scm env2498, struct scm z, struct scm s) {
    struct scm r127;
    struct scm r128;
    refcount_dec(env2498, 1);
    struct scm clor129;
    clor129 = s;
    r128 = z;
    scm_fptr clo130;
    struct scm env131;
    clo130 = clor129.val.v->elt[0].val.f;
    env131 = clor129.val.v->elt[1];
    refcount_inc_one(env131);
    r127 = clo130(env131, r128);
    refcount_dec_one(clor129);
    return r127;
}

struct scm g2502(struct scm env2498, struct scm z, struct scm s) {
    struct scm r132;
    refcount_dec(env2498, 1);
    refcount_dec(s, 1);
    r132 = z;
    return r132;
}

struct scm g2501(struct scm env2498, struct scm f, struct scm i, struct scm c) {
    struct scm r133;
    struct scm r134;
    struct scm r135;
    struct scm r136;
    struct scm r140;
    struct scm r141;
    struct scm r142;
    struct scm r143;
    struct scm r144;
    struct scm r145;
    struct scm r149;
    struct scm r150;
    struct scm r154;
    struct scm r155;
    refcount_inc(f, 1);
    refcount_inc(i, 1);
    struct scm clor137;
    clor137 = scm_wrap_fptr(scm_eq);
    r135 = i;
    r140 = (struct scm){ .tag = 0, .val.i = 0 };
    r141 = env2498;
    r142 = (struct scm){ .tag = 0, .val.i = 0 };
    r136 = scm_vector_ref(r140, r141, r142);
    scm_fptr clo138;
    struct scm env139;
    clo138 = clor137.val.v->elt[0].val.f;
    env139 = clor137.val.v->elt[1];
    refcount_inc_one(env139);
    r134 = clo138(env139, r135, r136);
    refcount_dec_one(clor137);
    if (scm_extract_truth(r134)) {
        refcount_dec(f, 2);
        refcount_dec(i, 1);
        r133 = c;
    } else {
        struct scm clor146;
        clor146 = f;
        r143 = f;
        struct scm clor151;
        clor151 = scm_wrap_fptr(scm_plus);
        r149 = (struct scm){ .tag = 0, .val.i = 1 };
        r150 = i;
        scm_fptr clo152;
        struct scm env153;
        clo152 = clor151.val.v->elt[0].val.f;
        env153 = clor151.val.v->elt[1];
        refcount_inc_one(env153);
        r144 = clo152(env153, r149, r150);
        refcount_dec_one(clor151);
        struct scm clor156;
        clor156 = scm_wrap_fptr(add);
        struct scm clor159;
        clor159 = scm_wrap_fptr(one);
        scm_fptr clo160;
        struct scm env161;
        clo160 = clor159.val.v->elt[0].val.f;
        env161 = clor159.val.v->elt[1];
        refcount_inc_one(env161);
        r154 = clo160(env161);
        refcount_dec_one(clor159);
        r155 = c;
        scm_fptr clo157;
        struct scm env158;
        clo157 = clor156.val.v->elt[0].val.f;
        env158 = clor156.val.v->elt[1];
        refcount_inc_one(env158);
        r145 = clo157(env158, r154, r155);
        refcount_dec_one(clor156);
        scm_fptr clo147;
        struct scm env148;
        clo147 = clor146.val.v->elt[0].val.f;
        env148 = clor146.val.v->elt[1];
        refcount_inc_one(env148);
        r133 = clo147(env148, r143, r144, r145);
        refcount_dec_one(clor146);
    }
    return r133;
}

struct scm g2500(struct scm env2498, struct scm aux) {
    struct scm r162;
    struct scm r163;
    struct scm r164;
    struct scm r165;
    refcount_dec(env2498, 1);
    refcount_inc(aux, 1);
    struct scm clor166;
    clor166 = aux;
    r163 = aux;
    r164 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor169;
    clor169 = scm_wrap_fptr(zero);
    scm_fptr clo170;
    struct scm env171;
    clo170 = clor169.val.v->elt[0].val.f;
    env171 = clor169.val.v->elt[1];
    refcount_inc_one(env171);
    r165 = clo170(env171);
    refcount_dec_one(clor169);
    scm_fptr clo167;
    struct scm env168;
    clo167 = clor166.val.v->elt[0].val.f;
    env168 = clor166.val.v->elt[1];
    refcount_inc_one(env168);
    r162 = clo167(env168, r163, r164, r165);
    refcount_dec_one(clor166);
    return r162;
}

struct scm g2499(struct scm env2498, struct scm i) {
    struct scm r172;
    struct scm r173;
    struct scm r174;
    refcount_dec(env2498, 1);
    struct scm clor175;
    clor175 = scm_wrap_fptr(scm_plus);
    r173 = (struct scm){ .tag = 0, .val.i = 1 };
    r174 = i;
    scm_fptr clo176;
    struct scm env177;
    clo176 = clor175.val.v->elt[0].val.f;
    env177 = clor175.val.v->elt[1];
    refcount_inc_one(env177);
    r172 = clo176(env177, r173, r174);
    refcount_dec_one(clor175);
    return r172;
}

