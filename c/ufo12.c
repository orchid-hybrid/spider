#include "runtime.c"
struct scm hash(struct scm);
struct scm space(struct scm);
struct scm classify(struct scm, struct scm);
struct scm not(struct scm, struct scm);
struct scm or(struct scm, struct scm, struct scm);
struct scm rule_30(struct scm, struct scm, struct scm, struct scm);
struct scm next(struct scm, struct scm, struct scm);
struct scm size(struct scm);
struct scm initial_condition(struct scm);
struct scm print_line(struct scm, struct scm);
struct scm do_times(struct scm, struct scm, struct scm);
struct scm scm_main(struct scm);
struct scm g2500(struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm hash(struct scm env2498) {
    struct scm r0;
    refcount_dec(env2498, 1);
    r0 = (struct scm){ .tag = 0, .val.i = 35 };
    return r0;
}

struct scm space(struct scm env2498) {
    struct scm r1;
    refcount_dec(env2498, 1);
    r1 = (struct scm){ .tag = 0, .val.i = 32 };
    return r1;
}

struct scm classify(struct scm env2498, struct scm chr) {
    struct scm r2;
    struct scm r3;
    struct scm r4;
    struct scm r5;
    refcount_dec(env2498, 1);
    struct scm clor6;
    clor6 = scm_wrap_fptr(scm_eq);
    r4 = chr;
    struct scm clor9;
    clor9 = scm_wrap_fptr(hash);
    scm_fptr clo10;
    struct scm env11;
    clo10 = clor9.val.v->elt[0].val.f;
    env11 = clor9.val.v->elt[1];
    refcount_inc_one(env11);
    r5 = clo10(env11);
    refcount_dec_one(clor9);
    scm_fptr clo7;
    struct scm env8;
    clo7 = clor6.val.v->elt[0].val.f;
    env8 = clor6.val.v->elt[1];
    refcount_inc_one(env8);
    r3 = clo7(env8, r4, r5);
    refcount_dec_one(clor6);
    if (scm_extract_truth(r3)) {
        r2 = (struct scm){ .tag = 0, .val.i = 1 };
    } else {
        r2 = (struct scm){ .tag = 0, .val.i = 0 };
    }
    return r2;
}

struct scm not(struct scm env2498, struct scm x) {
    struct scm r12;
    struct scm r13;
    refcount_dec(env2498, 1);
    r13 = x;
    if (scm_extract_truth(r13)) {
        r12 = (struct scm){ .tag = 0, .val.i = 0 };
    } else {
        r12 = (struct scm){ .tag = 0, .val.i = 1 };
    }
    return r12;
}

struct scm or(struct scm env2498, struct scm a, struct scm b) {
    struct scm r14;
    struct scm r15;
    refcount_dec(env2498, 1);
    r15 = a;
    if (scm_extract_truth(r15)) {
        refcount_dec(b, 1);
        r14 = (struct scm){ .tag = 0, .val.i = 1 };
    } else {
        r14 = b;
    }
    return r14;
}

struct scm rule_30(struct scm env2498, struct scm a, struct scm b, struct scm c) {
    struct scm r16;
    struct scm r17;
    struct scm r18;
    struct scm r19;
    struct scm r23;
    struct scm r24;
    struct scm r28;
    struct scm r29;
    struct scm r33;
    struct scm r34;
    struct scm r38;
    struct scm r39;
    refcount_dec(env2498, 1);
    refcount_inc(a, 1);
    refcount_inc(b, 1);
    r18 = a;
    if (scm_extract_truth(r18)) {
        refcount_dec(a, 1);
        refcount_dec(b, 1);
        struct scm clor20;
        clor20 = scm_wrap_fptr(not);
        struct scm clor25;
        clor25 = scm_wrap_fptr(or);
        r23 = b;
        r24 = c;
        scm_fptr clo26;
        struct scm env27;
        clo26 = clor25.val.v->elt[0].val.f;
        env27 = clor25.val.v->elt[1];
        refcount_inc_one(env27);
        r19 = clo26(env27, r23, r24);
        refcount_dec_one(clor25);
        scm_fptr clo21;
        struct scm env22;
        clo21 = clor20.val.v->elt[0].val.f;
        env22 = clor20.val.v->elt[1];
        refcount_inc_one(env22);
        r17 = clo21(env22, r19);
        refcount_dec_one(clor20);
    } else {
        r28 = b;
        if (scm_extract_truth(r28)) {
            refcount_dec(b, 1);
            refcount_dec(c, 1);
            struct scm clor30;
            clor30 = scm_wrap_fptr(not);
            r29 = a;
            scm_fptr clo31;
            struct scm env32;
            clo31 = clor30.val.v->elt[0].val.f;
            env32 = clor30.val.v->elt[1];
            refcount_inc_one(env32);
            r17 = clo31(env32, r29);
            refcount_dec_one(clor30);
        } else {
            r33 = c;
            if (scm_extract_truth(r33)) {
                struct scm clor35;
                clor35 = scm_wrap_fptr(not);
                struct scm clor40;
                clor40 = scm_wrap_fptr(or);
                r38 = a;
                r39 = b;
                scm_fptr clo41;
                struct scm env42;
                clo41 = clor40.val.v->elt[0].val.f;
                env42 = clor40.val.v->elt[1];
                refcount_inc_one(env42);
                r34 = clo41(env42, r38, r39);
                refcount_dec_one(clor40);
                scm_fptr clo36;
                struct scm env37;
                clo36 = clor35.val.v->elt[0].val.f;
                env37 = clor35.val.v->elt[1];
                refcount_inc_one(env37);
                r17 = clo36(env37, r34);
                refcount_dec_one(clor35);
            } else {
                refcount_dec(a, 1);
                refcount_dec(b, 1);
                r17 = (struct scm){ .tag = 0, .val.i = 0 };
            }
        }
    }
    if (scm_extract_truth(r17)) {
        struct scm clor43;
        clor43 = scm_wrap_fptr(hash);
        scm_fptr clo44;
        struct scm env45;
        clo44 = clor43.val.v->elt[0].val.f;
        env45 = clor43.val.v->elt[1];
        refcount_inc_one(env45);
        r16 = clo44(env45);
        refcount_dec_one(clor43);
    } else {
        struct scm clor46;
        clor46 = scm_wrap_fptr(space);
        scm_fptr clo47;
        struct scm env48;
        clo47 = clor46.val.v->elt[0].val.f;
        env48 = clor46.val.v->elt[1];
        refcount_inc_one(env48);
        r16 = clo47(env48);
        refcount_dec_one(clor46);
    }
    return r16;
}

struct scm next(struct scm env2498, struct scm vec, struct scm len) {
    struct scm r49;
    struct scm r50;
    struct scm r51;
    struct scm r52;
    refcount_dec(env2498, 1);
    r51 = len;
    r52 = vec;
    r50 = allocate_vector(2);
    scm_vector_insert_bang(r50, r51, 0);
    scm_vector_insert_bang(r50, r52, 1);
    r49 = make_closure(g2499, r50);
    return r49;
}

struct scm size(struct scm env2498) {
    struct scm r53;
    refcount_dec(env2498, 1);
    r53 = (struct scm){ .tag = 0, .val.i = 60 };
    return r53;
}

struct scm initial_condition(struct scm env2498) {
    struct scm r54;
    struct scm r55;
    struct scm r56;
    struct scm r63;
    refcount_dec(env2498, 1);
    struct scm clor57;
    clor57 = scm_wrap_fptr(scm_make_vector);
    struct scm clor60;
    clor60 = scm_wrap_fptr(size);
    scm_fptr clo61;
    struct scm env62;
    clo61 = clor60.val.v->elt[0].val.f;
    env62 = clor60.val.v->elt[1];
    refcount_inc_one(env62);
    r55 = clo61(env62);
    refcount_dec_one(clor60);
    r63 = allocate_vector(0);
    r56 = make_closure(g2500, r63);
    scm_fptr clo58;
    struct scm env59;
    clo58 = clor57.val.v->elt[0].val.f;
    env59 = clor57.val.v->elt[1];
    refcount_inc_one(env59);
    r54 = clo58(env59, r55, r56);
    refcount_dec_one(clor57);
    return r54;
}

struct scm print_line(struct scm env2498, struct scm l) {
    struct scm r64;
    struct scm r65;
    struct scm r69;
    refcount_dec(env2498, 1);
    struct scm clor66;
    clor66 = scm_wrap_fptr(scm_print);
    r65 = l;
    scm_fptr clo67;
    struct scm env68;
    clo67 = clor66.val.v->elt[0].val.f;
    env68 = clor66.val.v->elt[1];
    refcount_inc_one(env68);
    clo67(env68, r65);
    refcount_dec_one(clor66);
    struct scm clor70;
    clor70 = scm_wrap_fptr(scm_print);
    r69 = scm_string_to_vector("\n");
    scm_fptr clo71;
    struct scm env72;
    clo71 = clor70.val.v->elt[0].val.f;
    env72 = clor70.val.v->elt[1];
    refcount_inc_one(env72);
    r64 = clo71(env72, r69);
    refcount_dec_one(clor70);
    return r64;
}

struct scm do_times(struct scm env2498, struct scm n, struct scm state) {
    struct scm r73;
    struct scm r74;
    struct scm r78;
    struct scm r79;
    struct scm r80;
    struct scm r84;
    struct scm r85;
    struct scm r89;
    struct scm r90;
    struct scm r94;
    struct scm r95;
    struct scm r102;
    struct scm r103;
    refcount_dec(env2498, 1);
    refcount_inc(n, 1);
    refcount_inc(state, 1);
    struct scm clor75;
    clor75 = scm_wrap_fptr(print_line);
    r74 = state;
    scm_fptr clo76;
    struct scm env77;
    clo76 = clor75.val.v->elt[0].val.f;
    env77 = clor75.val.v->elt[1];
    refcount_inc_one(env77);
    clo76(env77, r74);
    refcount_dec_one(clor75);
    struct scm clor81;
    clor81 = scm_wrap_fptr(scm_eq);
    r79 = n;
    r80 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo82;
    struct scm env83;
    clo82 = clor81.val.v->elt[0].val.f;
    env83 = clor81.val.v->elt[1];
    refcount_inc_one(env83);
    r78 = clo82(env83, r79, r80);
    refcount_dec_one(clor81);
    if (scm_extract_truth(r78)) {
        refcount_dec(n, 1);
        refcount_dec(state, 1);
        r73 = (struct scm){ .tag = 0, .val.i = 0 };
    } else {
        struct scm clor86;
        clor86 = scm_wrap_fptr(do_times);
        struct scm clor91;
        clor91 = scm_wrap_fptr(scm_minus);
        r89 = n;
        r90 = (struct scm){ .tag = 0, .val.i = 1 };
        scm_fptr clo92;
        struct scm env93;
        clo92 = clor91.val.v->elt[0].val.f;
        env93 = clor91.val.v->elt[1];
        refcount_inc_one(env93);
        r84 = clo92(env93, r89, r90);
        refcount_dec_one(clor91);
        struct scm clor96;
        clor96 = scm_wrap_fptr(scm_make_vector);
        struct scm clor99;
        clor99 = scm_wrap_fptr(size);
        scm_fptr clo100;
        struct scm env101;
        clo100 = clor99.val.v->elt[0].val.f;
        env101 = clor99.val.v->elt[1];
        refcount_inc_one(env101);
        r94 = clo100(env101);
        refcount_dec_one(clor99);
        struct scm clor104;
        clor104 = scm_wrap_fptr(next);
        r102 = state;
        struct scm clor107;
        clor107 = scm_wrap_fptr(size);
        scm_fptr clo108;
        struct scm env109;
        clo108 = clor107.val.v->elt[0].val.f;
        env109 = clor107.val.v->elt[1];
        refcount_inc_one(env109);
        r103 = clo108(env109);
        refcount_dec_one(clor107);
        scm_fptr clo105;
        struct scm env106;
        clo105 = clor104.val.v->elt[0].val.f;
        env106 = clor104.val.v->elt[1];
        refcount_inc_one(env106);
        r95 = clo105(env106, r102, r103);
        refcount_dec_one(clor104);
        scm_fptr clo97;
        struct scm env98;
        clo97 = clor96.val.v->elt[0].val.f;
        env98 = clor96.val.v->elt[1];
        refcount_inc_one(env98);
        r85 = clo97(env98, r94, r95);
        refcount_dec_one(clor96);
        scm_fptr clo87;
        struct scm env88;
        clo87 = clor86.val.v->elt[0].val.f;
        env88 = clor86.val.v->elt[1];
        refcount_inc_one(env88);
        r73 = clo87(env88, r84, r85);
        refcount_dec_one(clor86);
    }
    return r73;
}

struct scm scm_main(struct scm env2498) {
    struct scm r110;
    struct scm r111;
    struct scm r112;
    refcount_dec(env2498, 1);
    struct scm clor113;
    clor113 = scm_wrap_fptr(do_times);
    struct scm clor116;
    clor116 = scm_wrap_fptr(size);
    scm_fptr clo117;
    struct scm env118;
    clo117 = clor116.val.v->elt[0].val.f;
    env118 = clor116.val.v->elt[1];
    refcount_inc_one(env118);
    r111 = clo117(env118);
    refcount_dec_one(clor116);
    struct scm clor119;
    clor119 = scm_wrap_fptr(initial_condition);
    scm_fptr clo120;
    struct scm env121;
    clo120 = clor119.val.v->elt[0].val.f;
    env121 = clor119.val.v->elt[1];
    refcount_inc_one(env121);
    r112 = clo120(env121);
    refcount_dec_one(clor119);
    scm_fptr clo114;
    struct scm env115;
    clo114 = clor113.val.v->elt[0].val.f;
    env115 = clor113.val.v->elt[1];
    refcount_inc_one(env115);
    r110 = clo114(env115, r111, r112);
    refcount_dec_one(clor113);
    return r110;
}

struct scm g2500(struct scm env2498, struct scm i) {
    struct scm r122;
    struct scm r123;
    struct scm r124;
    struct scm r125;
    struct scm r129;
    struct scm r130;
    refcount_dec(env2498, 1);
    struct scm clor126;
    clor126 = scm_wrap_fptr(scm_eq);
    r124 = i;
    struct scm clor131;
    clor131 = scm_wrap_fptr(scm_divide);
    struct scm clor134;
    clor134 = scm_wrap_fptr(size);
    scm_fptr clo135;
    struct scm env136;
    clo135 = clor134.val.v->elt[0].val.f;
    env136 = clor134.val.v->elt[1];
    refcount_inc_one(env136);
    r129 = clo135(env136);
    refcount_dec_one(clor134);
    r130 = (struct scm){ .tag = 0, .val.i = 2 };
    scm_fptr clo132;
    struct scm env133;
    clo132 = clor131.val.v->elt[0].val.f;
    env133 = clor131.val.v->elt[1];
    refcount_inc_one(env133);
    r125 = clo132(env133, r129, r130);
    refcount_dec_one(clor131);
    scm_fptr clo127;
    struct scm env128;
    clo127 = clor126.val.v->elt[0].val.f;
    env128 = clor126.val.v->elt[1];
    refcount_inc_one(env128);
    r123 = clo127(env128, r124, r125);
    refcount_dec_one(clor126);
    if (scm_extract_truth(r123)) {
        struct scm clor137;
        clor137 = scm_wrap_fptr(hash);
        scm_fptr clo138;
        struct scm env139;
        clo138 = clor137.val.v->elt[0].val.f;
        env139 = clor137.val.v->elt[1];
        refcount_inc_one(env139);
        r122 = clo138(env139);
        refcount_dec_one(clor137);
    } else {
        struct scm clor140;
        clor140 = scm_wrap_fptr(space);
        scm_fptr clo141;
        struct scm env142;
        clo141 = clor140.val.v->elt[0].val.f;
        env142 = clor140.val.v->elt[1];
        refcount_inc_one(env142);
        r122 = clo141(env142);
        refcount_dec_one(clor140);
    }
    return r122;
}

struct scm g2499(struct scm env2498, struct scm i) {
    struct scm r143;
    struct scm r144;
    struct scm r145;
    struct scm r146;
    struct scm r150;
    struct scm r151;
    struct scm r152;
    struct scm r156;
    struct scm r160;
    struct scm r161;
    struct scm r165;
    struct scm r166;
    struct scm r167;
    struct scm r168;
    struct scm r169;
    struct scm r173;
    struct scm r177;
    struct scm r178;
    struct scm r182;
    struct scm r183;
    struct scm r184;
    struct scm r185;
    struct scm r186;
    struct scm r187;
    struct scm r191;
    struct scm r192;
    struct scm r196;
    struct scm r197;
    struct scm r198;
    struct scm r199;
    struct scm r203;
    struct scm r204;
    struct scm r208;
    struct scm r209;
    struct scm r210;
    struct scm r211;
    struct scm r212;
    refcount_inc(env2498, 3);
    refcount_inc(i, 4);
    struct scm clor147;
    clor147 = scm_wrap_fptr(rule_30);
    struct scm clor153;
    clor153 = scm_wrap_fptr(scm_eq);
    r151 = i;
    r152 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo154;
    struct scm env155;
    clo154 = clor153.val.v->elt[0].val.f;
    env155 = clor153.val.v->elt[1];
    refcount_inc_one(env155);
    r150 = clo154(env155, r151, r152);
    refcount_dec_one(clor153);
    if (scm_extract_truth(r150)) {
        refcount_dec(i, 1);
        refcount_dec(env2498, 1);
        r144 = (struct scm){ .tag = 0, .val.i = 0 };
    } else {
        struct scm clor157;
        clor157 = scm_wrap_fptr(classify);
        struct scm clor162;
        clor162 = scm_wrap_fptr(scm_vector_ref);
        r165 = (struct scm){ .tag = 0, .val.i = 0 };
        r166 = env2498;
        r167 = (struct scm){ .tag = 0, .val.i = 1 };
        r160 = scm_vector_ref(r165, r166, r167);
        struct scm clor170;
        clor170 = scm_wrap_fptr(scm_minus);
        r168 = i;
        r169 = (struct scm){ .tag = 0, .val.i = 1 };
        scm_fptr clo171;
        struct scm env172;
        clo171 = clor170.val.v->elt[0].val.f;
        env172 = clor170.val.v->elt[1];
        refcount_inc_one(env172);
        r161 = clo171(env172, r168, r169);
        refcount_dec_one(clor170);
        scm_fptr clo163;
        struct scm env164;
        clo163 = clor162.val.v->elt[0].val.f;
        env164 = clor162.val.v->elt[1];
        refcount_inc_one(env164);
        r156 = clo163(env164, r160, r161);
        refcount_dec_one(clor162);
        scm_fptr clo158;
        struct scm env159;
        clo158 = clor157.val.v->elt[0].val.f;
        env159 = clor157.val.v->elt[1];
        refcount_inc_one(env159);
        r144 = clo158(env159, r156);
        refcount_dec_one(clor157);
    }
    struct scm clor174;
    clor174 = scm_wrap_fptr(classify);
    struct scm clor179;
    clor179 = scm_wrap_fptr(scm_vector_ref);
    r182 = (struct scm){ .tag = 0, .val.i = 0 };
    r183 = env2498;
    r184 = (struct scm){ .tag = 0, .val.i = 1 };
    r177 = scm_vector_ref(r182, r183, r184);
    r178 = i;
    scm_fptr clo180;
    struct scm env181;
    clo180 = clor179.val.v->elt[0].val.f;
    env181 = clor179.val.v->elt[1];
    refcount_inc_one(env181);
    r173 = clo180(env181, r177, r178);
    refcount_dec_one(clor179);
    scm_fptr clo175;
    struct scm env176;
    clo175 = clor174.val.v->elt[0].val.f;
    env176 = clor174.val.v->elt[1];
    refcount_inc_one(env176);
    r145 = clo175(env176, r173);
    refcount_dec_one(clor174);
    struct scm clor188;
    clor188 = scm_wrap_fptr(scm_eq);
    r186 = i;
    struct scm clor193;
    clor193 = scm_wrap_fptr(scm_minus);
    r196 = (struct scm){ .tag = 0, .val.i = 0 };
    r197 = env2498;
    r198 = (struct scm){ .tag = 0, .val.i = 0 };
    r191 = scm_vector_ref(r196, r197, r198);
    r192 = (struct scm){ .tag = 0, .val.i = 1 };
    scm_fptr clo194;
    struct scm env195;
    clo194 = clor193.val.v->elt[0].val.f;
    env195 = clor193.val.v->elt[1];
    refcount_inc_one(env195);
    r187 = clo194(env195, r191, r192);
    refcount_dec_one(clor193);
    scm_fptr clo189;
    struct scm env190;
    clo189 = clor188.val.v->elt[0].val.f;
    env190 = clor188.val.v->elt[1];
    refcount_inc_one(env190);
    r185 = clo189(env190, r186, r187);
    refcount_dec_one(clor188);
    if (scm_extract_truth(r185)) {
        refcount_dec(i, 1);
        refcount_dec(env2498, 1);
        r146 = (struct scm){ .tag = 0, .val.i = 0 };
    } else {
        struct scm clor200;
        clor200 = scm_wrap_fptr(classify);
        struct scm clor205;
        clor205 = scm_wrap_fptr(scm_vector_ref);
        r208 = (struct scm){ .tag = 0, .val.i = 0 };
        r209 = env2498;
        r210 = (struct scm){ .tag = 0, .val.i = 1 };
        r203 = scm_vector_ref(r208, r209, r210);
        struct scm clor213;
        clor213 = scm_wrap_fptr(scm_plus);
        r211 = i;
        r212 = (struct scm){ .tag = 0, .val.i = 1 };
        scm_fptr clo214;
        struct scm env215;
        clo214 = clor213.val.v->elt[0].val.f;
        env215 = clor213.val.v->elt[1];
        refcount_inc_one(env215);
        r204 = clo214(env215, r211, r212);
        refcount_dec_one(clor213);
        scm_fptr clo206;
        struct scm env207;
        clo206 = clor205.val.v->elt[0].val.f;
        env207 = clor205.val.v->elt[1];
        refcount_inc_one(env207);
        r199 = clo206(env207, r203, r204);
        refcount_dec_one(clor205);
        scm_fptr clo201;
        struct scm env202;
        clo201 = clor200.val.v->elt[0].val.f;
        env202 = clor200.val.v->elt[1];
        refcount_inc_one(env202);
        r146 = clo201(env202, r199);
        refcount_dec_one(clor200);
    }
    scm_fptr clo148;
    struct scm env149;
    clo148 = clor147.val.v->elt[0].val.f;
    env149 = clor147.val.v->elt[1];
    refcount_inc_one(env149);
    r143 = clo148(env149, r144, r145, r146);
    refcount_dec_one(clor147);
    return r143;
}

