#include "runtime.c"
struct scm cons(struct scm, struct scm, struct scm);
struct scm car(struct scm, struct scm);
struct scm cdr(struct scm, struct scm);
struct scm begin(struct scm, struct scm, struct scm);
struct scm for_each(struct scm, struct scm, struct scm);
struct scm map(struct scm, struct scm, struct scm);
struct scm append(struct scm, struct scm, struct scm);
struct scm reverse_aux(struct scm, struct scm, struct scm);
struct scm reverse(struct scm, struct scm);
struct scm forward_backwards(struct scm, struct scm, struct scm);
struct scm foo(struct scm, struct scm, struct scm, struct scm);
struct scm print_numbers(struct scm, struct scm, struct scm);
struct scm scm_main(struct scm);
struct scm g2505(struct scm, struct scm, struct scm);
struct scm g2504(struct scm, struct scm);
struct scm g2503(struct scm, struct scm);
struct scm g2502(struct scm, struct scm);
struct scm g2501(struct scm, struct scm, struct scm);
struct scm g2500(struct scm, struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm cons(struct scm env2498, struct scm x, struct scm y) {
    struct scm r0;
    struct scm r1;
    struct scm r2;
    struct scm r3;
    refcount_dec(env2498);
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
    refcount_dec(env2498);
    struct scm clor6;
    clor6 = c;
    r9 = allocate_vector(0);
    r5 = make_closure(g2500, r9);
    scm_fptr clo7;
    struct scm env8;
    clo7 = clor6.val.v->elt[0].val.f;
    env8 = clor6.val.v->elt[1];
    r4 = clo7(env8, r5);
    return r4;
}

struct scm cdr(struct scm env2498, struct scm c) {
    struct scm r10;
    struct scm r11;
    struct scm r15;
    refcount_dec(env2498);
    struct scm clor12;
    clor12 = c;
    r15 = allocate_vector(0);
    r11 = make_closure(g2501, r15);
    scm_fptr clo13;
    struct scm env14;
    clo13 = clor12.val.v->elt[0].val.f;
    env14 = clor12.val.v->elt[1];
    r10 = clo13(env14, r11);
    return r10;
}

struct scm begin(struct scm env2498, struct scm a, struct scm b) {
    struct scm r16;
    refcount_dec(env2498);
    refcount_dec(a);
    r16 = b;
    return r16;
}

struct scm for_each(struct scm env2498, struct scm f, struct scm l) {
    struct scm r17;
    struct scm r18;
    struct scm r19;
    struct scm r20;
    struct scm r24;
    struct scm r28;
    struct scm r32;
    struct scm r33;
    struct scm r37;
    refcount_dec(env2498);
    refcount_inc(f, 1);
    refcount_inc(l, 2);
    r18 = l;
    if (scm_extract_truth(r18)) {
        struct scm clor21;
        clor21 = scm_wrap_fptr(begin);
        struct scm clor25;
        clor25 = f;
        struct scm clor29;
        clor29 = scm_wrap_fptr(car);
        r28 = l;
        scm_fptr clo30;
        struct scm env31;
        clo30 = clor29.val.v->elt[0].val.f;
        env31 = clor29.val.v->elt[1];
        r24 = clo30(env31, r28);
        scm_fptr clo26;
        struct scm env27;
        clo26 = clor25.val.v->elt[0].val.f;
        env27 = clor25.val.v->elt[1];
        r19 = clo26(env27, r24);
        struct scm clor34;
        clor34 = scm_wrap_fptr(for_each);
        r32 = f;
        struct scm clor38;
        clor38 = scm_wrap_fptr(cdr);
        r37 = l;
        scm_fptr clo39;
        struct scm env40;
        clo39 = clor38.val.v->elt[0].val.f;
        env40 = clor38.val.v->elt[1];
        r33 = clo39(env40, r37);
        scm_fptr clo35;
        struct scm env36;
        clo35 = clor34.val.v->elt[0].val.f;
        env36 = clor34.val.v->elt[1];
        r20 = clo35(env36, r32, r33);
        scm_fptr clo22;
        struct scm env23;
        clo22 = clor21.val.v->elt[0].val.f;
        env23 = clor21.val.v->elt[1];
        r17 = clo22(env23, r19, r20);
    } else {
        r17 = (struct scm){ .tag = 0, .val.i = 0 };
    }
    return r17;
}

struct scm map(struct scm env2498, struct scm f, struct scm l) {
    struct scm r41;
    struct scm r42;
    struct scm r43;
    struct scm r44;
    struct scm r48;
    struct scm r52;
    struct scm r56;
    struct scm r57;
    struct scm r61;
    refcount_dec(env2498);
    refcount_inc(f, 1);
    refcount_inc(l, 2);
    r42 = l;
    if (scm_extract_truth(r42)) {
        struct scm clor45;
        clor45 = scm_wrap_fptr(cons);
        struct scm clor49;
        clor49 = f;
        struct scm clor53;
        clor53 = scm_wrap_fptr(car);
        r52 = l;
        scm_fptr clo54;
        struct scm env55;
        clo54 = clor53.val.v->elt[0].val.f;
        env55 = clor53.val.v->elt[1];
        r48 = clo54(env55, r52);
        scm_fptr clo50;
        struct scm env51;
        clo50 = clor49.val.v->elt[0].val.f;
        env51 = clor49.val.v->elt[1];
        r43 = clo50(env51, r48);
        struct scm clor58;
        clor58 = scm_wrap_fptr(map);
        r56 = f;
        struct scm clor62;
        clor62 = scm_wrap_fptr(cdr);
        r61 = l;
        scm_fptr clo63;
        struct scm env64;
        clo63 = clor62.val.v->elt[0].val.f;
        env64 = clor62.val.v->elt[1];
        r57 = clo63(env64, r61);
        scm_fptr clo59;
        struct scm env60;
        clo59 = clor58.val.v->elt[0].val.f;
        env60 = clor58.val.v->elt[1];
        r44 = clo59(env60, r56, r57);
        scm_fptr clo46;
        struct scm env47;
        clo46 = clor45.val.v->elt[0].val.f;
        env47 = clor45.val.v->elt[1];
        r41 = clo46(env47, r43, r44);
    } else {
        r41 = (struct scm){ .tag = 0, .val.i = 0 };
    }
    return r41;
}

struct scm append(struct scm env2498, struct scm a, struct scm b) {
    struct scm r65;
    struct scm r66;
    struct scm r67;
    struct scm r68;
    struct scm r72;
    struct scm r76;
    struct scm r77;
    struct scm r81;
    refcount_dec(env2498);
    refcount_inc(a, 2);
    refcount_inc(b, 1);
    r66 = a;
    if (scm_extract_truth(r66)) {
        struct scm clor69;
        clor69 = scm_wrap_fptr(cons);
        struct scm clor73;
        clor73 = scm_wrap_fptr(car);
        r72 = a;
        scm_fptr clo74;
        struct scm env75;
        clo74 = clor73.val.v->elt[0].val.f;
        env75 = clor73.val.v->elt[1];
        r67 = clo74(env75, r72);
        struct scm clor78;
        clor78 = scm_wrap_fptr(append);
        struct scm clor82;
        clor82 = scm_wrap_fptr(cdr);
        r81 = a;
        scm_fptr clo83;
        struct scm env84;
        clo83 = clor82.val.v->elt[0].val.f;
        env84 = clor82.val.v->elt[1];
        r76 = clo83(env84, r81);
        r77 = b;
        scm_fptr clo79;
        struct scm env80;
        clo79 = clor78.val.v->elt[0].val.f;
        env80 = clor78.val.v->elt[1];
        r68 = clo79(env80, r76, r77);
        scm_fptr clo70;
        struct scm env71;
        clo70 = clor69.val.v->elt[0].val.f;
        env71 = clor69.val.v->elt[1];
        r65 = clo70(env71, r67, r68);
    } else {
        r65 = b;
    }
    return r65;
}

struct scm reverse_aux(struct scm env2498, struct scm ls, struct scm o) {
    struct scm r85;
    struct scm r86;
    struct scm r87;
    struct scm r88;
    struct scm r92;
    struct scm r96;
    struct scm r97;
    struct scm r101;
    refcount_dec(env2498);
    refcount_inc(ls, 2);
    refcount_inc(o, 1);
    r86 = ls;
    if (scm_extract_truth(r86)) {
        struct scm clor89;
        clor89 = scm_wrap_fptr(reverse_aux);
        struct scm clor93;
        clor93 = scm_wrap_fptr(cdr);
        r92 = ls;
        scm_fptr clo94;
        struct scm env95;
        clo94 = clor93.val.v->elt[0].val.f;
        env95 = clor93.val.v->elt[1];
        r87 = clo94(env95, r92);
        struct scm clor98;
        clor98 = scm_wrap_fptr(cons);
        struct scm clor102;
        clor102 = scm_wrap_fptr(car);
        r101 = ls;
        scm_fptr clo103;
        struct scm env104;
        clo103 = clor102.val.v->elt[0].val.f;
        env104 = clor102.val.v->elt[1];
        r96 = clo103(env104, r101);
        r97 = o;
        scm_fptr clo99;
        struct scm env100;
        clo99 = clor98.val.v->elt[0].val.f;
        env100 = clor98.val.v->elt[1];
        r88 = clo99(env100, r96, r97);
        scm_fptr clo90;
        struct scm env91;
        clo90 = clor89.val.v->elt[0].val.f;
        env91 = clor89.val.v->elt[1];
        r85 = clo90(env91, r87, r88);
    } else {
        r85 = o;
    }
    return r85;
}

struct scm reverse(struct scm env2498, struct scm ls) {
    struct scm r105;
    struct scm r106;
    struct scm r107;
    refcount_dec(env2498);
    struct scm clor108;
    clor108 = scm_wrap_fptr(reverse_aux);
    r106 = ls;
    r107 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo109;
    struct scm env110;
    clo109 = clor108.val.v->elt[0].val.f;
    env110 = clor108.val.v->elt[1];
    r105 = clo109(env110, r106, r107);
    return r105;
}

struct scm forward_backwards(struct scm env2498, struct scm l_r, struct scm k) {
    struct scm r111;
    struct scm r112;
    struct scm r113;
    struct scm r117;
    refcount_dec(env2498);
    refcount_inc(l_r, 1);
    struct scm clor114;
    clor114 = k;
    r112 = l_r;
    struct scm clor118;
    clor118 = scm_wrap_fptr(reverse);
    r117 = l_r;
    scm_fptr clo119;
    struct scm env120;
    clo119 = clor118.val.v->elt[0].val.f;
    env120 = clor118.val.v->elt[1];
    r113 = clo119(env120, r117);
    scm_fptr clo115;
    struct scm env116;
    clo115 = clor114.val.v->elt[0].val.f;
    env116 = clor114.val.v->elt[1];
    r111 = clo115(env116, r112, r113);
    return r111;
}

struct scm foo(struct scm env2498, struct scm l, struct scm r, struct scm n) {
    struct scm r121;
    struct scm r122;
    struct scm r123;
    struct scm r124;
    struct scm r128;
    struct scm r129;
    struct scm r133;
    struct scm r134;
    struct scm r135;
    struct scm r136;
    struct scm r140;
    struct scm r141;
    refcount_dec(env2498);
    refcount_inc(l, 1);
    refcount_inc(r, 1);
    refcount_inc(n, 1);
    r122 = n;
    if (scm_extract_truth(r122)) {
        struct scm clor125;
        clor125 = scm_wrap_fptr(forward_backwards);
        struct scm clor130;
        clor130 = scm_wrap_fptr(append);
        r128 = l;
        r129 = r;
        scm_fptr clo131;
        struct scm env132;
        clo131 = clor130.val.v->elt[0].val.f;
        env132 = clor130.val.v->elt[1];
        r123 = clo131(env132, r128, r129);
        r134 = n;
        r133 = allocate_vector(1);
        scm_vector_insert_bang(r133, r134, 0);
        r124 = make_closure(g2505, r133);
        scm_fptr clo126;
        struct scm env127;
        clo126 = clor125.val.v->elt[0].val.f;
        env127 = clor125.val.v->elt[1];
        r121 = clo126(env127, r123, r124);
    } else {
        struct scm clor137;
        clor137 = scm_wrap_fptr(print_numbers);
        struct scm clor142;
        clor142 = scm_wrap_fptr(append);
        r140 = l;
        r141 = r;
        scm_fptr clo143;
        struct scm env144;
        clo143 = clor142.val.v->elt[0].val.f;
        env144 = clor142.val.v->elt[1];
        r135 = clo143(env144, r140, r141);
        r136 = (struct scm){ .tag = 0, .val.i = 0 };
        scm_fptr clo138;
        struct scm env139;
        clo138 = clor137.val.v->elt[0].val.f;
        env139 = clor137.val.v->elt[1];
        r121 = clo138(env139, r135, r136);
    }
    return r121;
}

struct scm print_numbers(struct scm env2498, struct scm l, struct scm n) {
    struct scm r145;
    struct scm r146;
    struct scm r147;
    struct scm r148;
    struct scm r152;
    struct scm r156;
    struct scm r157;
    struct scm r161;
    struct scm r165;
    struct scm r166;
    struct scm r170;
    struct scm r171;
    struct scm r175;
    struct scm r179;
    struct scm r180;
    struct scm r184;
    struct scm r188;
    struct scm r189;
    refcount_dec(env2498);
    refcount_inc(l, 2);
    refcount_inc(n, 1);
    r146 = l;
    if (scm_extract_truth(r146)) {
        struct scm clor149;
        clor149 = scm_wrap_fptr(begin);
        struct scm clor153;
        clor153 = scm_wrap_fptr(scm_print);
        r152 = scm_string_to_vector("\n");
        scm_fptr clo154;
        struct scm env155;
        clo154 = clor153.val.v->elt[0].val.f;
        env155 = clor153.val.v->elt[1];
        r147 = clo154(env155, r152);
        struct scm clor158;
        clor158 = scm_wrap_fptr(begin);
        struct scm clor162;
        clor162 = scm_wrap_fptr(scm_print);
        r161 = n;
        scm_fptr clo163;
        struct scm env164;
        clo163 = clor162.val.v->elt[0].val.f;
        env164 = clor162.val.v->elt[1];
        r156 = clo163(env164, r161);
        struct scm clor167;
        clor167 = scm_wrap_fptr(begin);
        struct scm clor172;
        clor172 = scm_wrap_fptr(for_each);
        r170 = scm_wrap_fptr(scm_print);
        struct scm clor176;
        clor176 = scm_wrap_fptr(car);
        r175 = l;
        scm_fptr clo177;
        struct scm env178;
        clo177 = clor176.val.v->elt[0].val.f;
        env178 = clor176.val.v->elt[1];
        r171 = clo177(env178, r175);
        scm_fptr clo173;
        struct scm env174;
        clo173 = clor172.val.v->elt[0].val.f;
        env174 = clor172.val.v->elt[1];
        r165 = clo173(env174, r170, r171);
        struct scm clor181;
        clor181 = scm_wrap_fptr(print_numbers);
        struct scm clor185;
        clor185 = scm_wrap_fptr(cdr);
        r184 = l;
        scm_fptr clo186;
        struct scm env187;
        clo186 = clor185.val.v->elt[0].val.f;
        env187 = clor185.val.v->elt[1];
        r179 = clo186(env187, r184);
        struct scm clor190;
        clor190 = scm_wrap_fptr(scm_plus);
        r188 = n;
        r189 = (struct scm){ .tag = 0, .val.i = 1 };
        scm_fptr clo191;
        struct scm env192;
        clo191 = clor190.val.v->elt[0].val.f;
        env192 = clor190.val.v->elt[1];
        r180 = clo191(env192, r188, r189);
        scm_fptr clo182;
        struct scm env183;
        clo182 = clor181.val.v->elt[0].val.f;
        env183 = clor181.val.v->elt[1];
        r166 = clo182(env183, r179, r180);
        scm_fptr clo168;
        struct scm env169;
        clo168 = clor167.val.v->elt[0].val.f;
        env169 = clor167.val.v->elt[1];
        r157 = clo168(env169, r165, r166);
        scm_fptr clo159;
        struct scm env160;
        clo159 = clor158.val.v->elt[0].val.f;
        env160 = clor158.val.v->elt[1];
        r148 = clo159(env160, r156, r157);
        scm_fptr clo150;
        struct scm env151;
        clo150 = clor149.val.v->elt[0].val.f;
        env151 = clor149.val.v->elt[1];
        r145 = clo150(env151, r147, r148);
    } else {
        r145 = (struct scm){ .tag = 0, .val.i = 0 };
    }
    return r145;
}

struct scm scm_main(struct scm env2498) {
    struct scm r193;
    struct scm r194;
    struct scm r195;
    struct scm r196;
    struct scm r200;
    struct scm r201;
    struct scm r205;
    struct scm r206;
    struct scm r210;
    struct scm r211;
    struct scm r215;
    struct scm r216;
    refcount_dec(env2498);
    struct scm clor197;
    clor197 = scm_wrap_fptr(foo);
    struct scm clor202;
    clor202 = scm_wrap_fptr(cons);
    struct scm clor207;
    clor207 = scm_wrap_fptr(cons);
    r205 = scm_string_to_vector("0");
    r206 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo208;
    struct scm env209;
    clo208 = clor207.val.v->elt[0].val.f;
    env209 = clor207.val.v->elt[1];
    r200 = clo208(env209, r205, r206);
    r201 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo203;
    struct scm env204;
    clo203 = clor202.val.v->elt[0].val.f;
    env204 = clor202.val.v->elt[1];
    r194 = clo203(env204, r200, r201);
    struct scm clor212;
    clor212 = scm_wrap_fptr(cons);
    struct scm clor217;
    clor217 = scm_wrap_fptr(cons);
    r215 = scm_string_to_vector("1");
    r216 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo218;
    struct scm env219;
    clo218 = clor217.val.v->elt[0].val.f;
    env219 = clor217.val.v->elt[1];
    r210 = clo218(env219, r215, r216);
    r211 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo213;
    struct scm env214;
    clo213 = clor212.val.v->elt[0].val.f;
    env214 = clor212.val.v->elt[1];
    r195 = clo213(env214, r210, r211);
    r196 = (struct scm){ .tag = 0, .val.i = 4 };
    scm_fptr clo198;
    struct scm env199;
    clo198 = clor197.val.v->elt[0].val.f;
    env199 = clor197.val.v->elt[1];
    r193 = clo198(env199, r194, r195, r196);
    return r193;
}

struct scm g2505(struct scm env2498, struct scm fwd, struct scm bwd) {
    struct scm r220;
    struct scm r221;
    struct scm r222;
    struct scm r226;
    struct scm r227;
    struct scm r231;
    struct scm r232;
    struct scm r233;
    struct scm r237;
    struct scm r241;
    struct scm r242;
    struct scm r243;
    struct scm r247;
    struct scm r248;
    struct scm r252;
    struct scm r253;
    struct scm r254;
    struct scm r258;
    struct scm r259;
    struct scm r260;
    struct scm r264;
    struct scm r265;
    struct scm r266;
    refcount_inc(fwd, 1);
    struct scm clor223;
    clor223 = scm_wrap_fptr(begin);
    struct scm clor228;
    clor228 = scm_wrap_fptr(for_each);
    r231 = allocate_vector(0);
    r226 = make_closure(g2502, r231);
    r227 = fwd;
    scm_fptr clo229;
    struct scm env230;
    clo229 = clor228.val.v->elt[0].val.f;
    env230 = clor228.val.v->elt[1];
    r221 = clo229(env230, r226, r227);
    struct scm clor234;
    clor234 = scm_wrap_fptr(begin);
    struct scm clor238;
    clor238 = scm_wrap_fptr(scm_print);
    r237 = scm_string_to_vector("\n");
    scm_fptr clo239;
    struct scm env240;
    clo239 = clor238.val.v->elt[0].val.f;
    env240 = clor238.val.v->elt[1];
    r232 = clo239(env240, r237);
    struct scm clor244;
    clor244 = scm_wrap_fptr(foo);
    struct scm clor249;
    clor249 = scm_wrap_fptr(map);
    r252 = allocate_vector(0);
    r247 = make_closure(g2503, r252);
    r248 = fwd;
    scm_fptr clo250;
    struct scm env251;
    clo250 = clor249.val.v->elt[0].val.f;
    env251 = clor249.val.v->elt[1];
    r241 = clo250(env251, r247, r248);
    struct scm clor255;
    clor255 = scm_wrap_fptr(map);
    r258 = allocate_vector(0);
    r253 = make_closure(g2504, r258);
    r254 = bwd;
    scm_fptr clo256;
    struct scm env257;
    clo256 = clor255.val.v->elt[0].val.f;
    env257 = clor255.val.v->elt[1];
    r242 = clo256(env257, r253, r254);
    struct scm clor261;
    clor261 = scm_wrap_fptr(scm_minus);
    r264 = (struct scm){ .tag = 0, .val.i = 0 };
    r265 = env2498;
    r266 = (struct scm){ .tag = 0, .val.i = 0 };
    r259 = scm_vector_ref(r264, r265, r266);
    r260 = (struct scm){ .tag = 0, .val.i = 1 };
    scm_fptr clo262;
    struct scm env263;
    clo262 = clor261.val.v->elt[0].val.f;
    env263 = clor261.val.v->elt[1];
    r243 = clo262(env263, r259, r260);
    scm_fptr clo245;
    struct scm env246;
    clo245 = clor244.val.v->elt[0].val.f;
    env246 = clor244.val.v->elt[1];
    r233 = clo245(env246, r241, r242, r243);
    scm_fptr clo235;
    struct scm env236;
    clo235 = clor234.val.v->elt[0].val.f;
    env236 = clor234.val.v->elt[1];
    r222 = clo235(env236, r232, r233);
    scm_fptr clo224;
    struct scm env225;
    clo224 = clor223.val.v->elt[0].val.f;
    env225 = clor223.val.v->elt[1];
    r220 = clo224(env225, r221, r222);
    return r220;
}

struct scm g2504(struct scm env2498, struct scm c) {
    struct scm r267;
    struct scm r268;
    struct scm r269;
    refcount_dec(env2498);
    struct scm clor270;
    clor270 = scm_wrap_fptr(cons);
    r268 = scm_string_to_vector("1");
    r269 = c;
    scm_fptr clo271;
    struct scm env272;
    clo271 = clor270.val.v->elt[0].val.f;
    env272 = clor270.val.v->elt[1];
    r267 = clo271(env272, r268, r269);
    return r267;
}

struct scm g2503(struct scm env2498, struct scm c) {
    struct scm r273;
    struct scm r274;
    struct scm r275;
    refcount_dec(env2498);
    struct scm clor276;
    clor276 = scm_wrap_fptr(cons);
    r274 = scm_string_to_vector("0");
    r275 = c;
    scm_fptr clo277;
    struct scm env278;
    clo277 = clor276.val.v->elt[0].val.f;
    env278 = clor276.val.v->elt[1];
    r273 = clo277(env278, r274, r275);
    return r273;
}

struct scm g2502(struct scm env2498, struct scm c) {
    struct scm r279;
    struct scm r280;
    struct scm r281;
    refcount_dec(env2498);
    struct scm clor282;
    clor282 = scm_wrap_fptr(for_each);
    r280 = scm_wrap_fptr(scm_print);
    r281 = c;
    scm_fptr clo283;
    struct scm env284;
    clo283 = clor282.val.v->elt[0].val.f;
    env284 = clor282.val.v->elt[1];
    r279 = clo283(env284, r280, r281);
    return r279;
}

struct scm g2501(struct scm env2498, struct scm x, struct scm y) {
    struct scm r285;
    refcount_dec(env2498);
    refcount_dec(x);
    r285 = y;
    return r285;
}

struct scm g2500(struct scm env2498, struct scm x, struct scm y) {
    struct scm r286;
    refcount_dec(env2498);
    refcount_dec(y);
    r286 = x;
    return r286;
}

struct scm g2499(struct scm env2498, struct scm selector) {
    struct scm r287;
    struct scm r288;
    struct scm r289;
    struct scm r293;
    struct scm r294;
    struct scm r295;
    struct scm r296;
    struct scm r297;
    struct scm r298;
    refcount_inc(env2498, 1);
    struct scm clor290;
    clor290 = selector;
    r293 = (struct scm){ .tag = 0, .val.i = 0 };
    r294 = env2498;
    r295 = (struct scm){ .tag = 0, .val.i = 1 };
    r288 = scm_vector_ref(r293, r294, r295);
    r296 = (struct scm){ .tag = 0, .val.i = 0 };
    r297 = env2498;
    r298 = (struct scm){ .tag = 0, .val.i = 0 };
    r289 = scm_vector_ref(r296, r297, r298);
    scm_fptr clo291;
    struct scm env292;
    clo291 = clor290.val.v->elt[0].val.f;
    env292 = clor290.val.v->elt[1];
    r287 = clo291(env292, r288, r289);
    return r287;
}

