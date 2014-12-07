#include "runtime.c"

#define BLURT printf ("", "This is line %d of file %s (function %s)\n",  \
                      __LINE__, __FILE__, __func__)

struct scm hash(struct scm);
struct scm space(struct scm);
struct scm classify(struct scm, struct scm);
struct scm not(struct scm, struct scm);
struct scm or(struct scm, struct scm, struct scm);
struct scm rule_30(struct scm, struct scm, struct scm, struct scm);
struct scm next(struct scm, struct scm, struct scm);
struct scm size(struct scm);
struct scm initial_condition(struct scm);
struct scm begin(struct scm, struct scm, struct scm);
struct scm print_line(struct scm, struct scm);
struct scm do_times(struct scm, struct scm, struct scm);
struct scm scm_main(struct scm);
struct scm g2500(struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm hash(struct scm env2498) { BLURT;
    struct scm r0;
    r0 = (struct scm){ .tag = 0, .val.i = 35 };
    return r0;
}

struct scm space(struct scm env2498) { BLURT;
    struct scm r1;
    r1 = (struct scm){ .tag = 0, .val.i = 32 };
    return r1;
}

struct scm classify(struct scm env2498, struct scm chr) { BLURT;
    struct scm r2;
    struct scm r3;
    struct scm r4;
    struct scm r5;
    struct scm clor6;
    clor6 = scm_wrap_fptr(scm_eq);
    r4 = chr;
    struct scm clor9;
    clor9 = scm_wrap_fptr(hash);
    scm_fptr clo10;
    struct scm env11;
    clo10 = clor9.val.v->elt[0].val.f;
    env11 = clor9.val.v->elt[1];
    r5 = clo10(env11);
    scm_fptr clo7;
    struct scm env8;
    clo7 = clor6.val.v->elt[0].val.f;
    env8 = clor6.val.v->elt[1];
    r3 = clo7(env8, r4, r5);
    if (scm_extract_truth(r3)) {
        r2 = (struct scm){ .tag = 0, .val.i = 1 };
    } else {
        r2 = (struct scm){ .tag = 0, .val.i = 0 };
    }
    return r2;
}

struct scm not(struct scm env2498, struct scm x) { BLURT;
    struct scm r12;
    struct scm r13;
    r13 = x;
    if (scm_extract_truth(r13)) {
        r12 = (struct scm){ .tag = 0, .val.i = 0 };
    } else {
        r12 = (struct scm){ .tag = 0, .val.i = 1 };
    }
    return r12;
}

struct scm or(struct scm env2498, struct scm a, struct scm b) { BLURT;
    struct scm r14;
    struct scm r15;
    r15 = a;
    if (scm_extract_truth(r15)) {
        r14 = (struct scm){ .tag = 0, .val.i = 1 };
    } else {
        r14 = b;
    }
    return r14;
}

struct scm rule_30(struct scm env2498, struct scm a, struct scm b, struct scm c) { BLURT;
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
    r18 = a;
    if (scm_extract_truth(r18)) {
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
        r19 = clo26(env27, r23, r24);
        scm_fptr clo21;
        struct scm env22;
        clo21 = clor20.val.v->elt[0].val.f;
        env22 = clor20.val.v->elt[1];
        r17 = clo21(env22, r19);
    } else {
        r28 = b;
        if (scm_extract_truth(r28)) {
            struct scm clor30;
            clor30 = scm_wrap_fptr(not);
            r29 = a;
            scm_fptr clo31;
            struct scm env32;
            clo31 = clor30.val.v->elt[0].val.f;
            env32 = clor30.val.v->elt[1];
            r17 = clo31(env32, r29);
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
                r34 = clo41(env42, r38, r39);
                scm_fptr clo36;
                struct scm env37;
                clo36 = clor35.val.v->elt[0].val.f;
                env37 = clor35.val.v->elt[1];
                r17 = clo36(env37, r34);
            } else {
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
        r16 = clo44(env45);
    } else {
        struct scm clor46;
        clor46 = scm_wrap_fptr(space);
        scm_fptr clo47;
        struct scm env48;
        clo47 = clor46.val.v->elt[0].val.f;
        env48 = clor46.val.v->elt[1];
        r16 = clo47(env48);
    }
    return r16;
}

struct scm next(struct scm env2498, struct scm vec, struct scm len) { BLURT;
    struct scm r49;
    struct scm r50;
    struct scm r51;
    struct scm r52;
    r51 = len;
    r52 = vec;
    r50 = allocate_vector(2);
    //printf("HERE 1 %d\n", r50.tag);
    scm_vector_insert_bang(r50, r51, 0);
    //printf("HERE 2 %d\n", r50.tag);
    scm_vector_insert_bang(r50, r52, 1);
    //printf("HERE 3 %d\n", r50.tag);
    r49 = make_closure(g2499, r50);
    //printf("HERE 4 %d\n", r50.tag);
    return r49;
}

struct scm size(struct scm env2498) { BLURT;
    struct scm r53;
    r53 = (struct scm){ .tag = 0, .val.i = 60 };
    return r53;
}

struct scm initial_condition(struct scm env2498) { BLURT;
    struct scm r54;
    struct scm r55;
    struct scm r56;
    struct scm r63;
    struct scm clor57;
    clor57 = scm_wrap_fptr(scm_make_vector);
    struct scm clor60;
    clor60 = scm_wrap_fptr(size);
    scm_fptr clo61;
    struct scm env62;
    clo61 = clor60.val.v->elt[0].val.f;
    env62 = clor60.val.v->elt[1];
    r55 = clo61(env62);
    r63 = allocate_vector(0);
    r56 = make_closure(g2500, r63);
    scm_fptr clo58;
    struct scm env59;
    clo58 = clor57.val.v->elt[0].val.f;
    env59 = clor57.val.v->elt[1];
    r54 = clo58(env59, r55, r56);
    return r54;
}

struct scm begin(struct scm env2498, struct scm x, struct scm y) { BLURT;
    struct scm r64;
    r64 = y;
    return r64;
}

struct scm print_line(struct scm env2498, struct scm l) { BLURT;
    struct scm r65;
    struct scm r66;
    struct scm r67;
    struct scm r71;
    struct scm r75;
    struct scm clor68;
    clor68 = scm_wrap_fptr(begin);
    struct scm clor72;
    clor72 = scm_wrap_fptr(scm_print);
    r71 = l;
    scm_fptr clo73;
    struct scm env74;
    clo73 = clor72.val.v->elt[0].val.f;
    env74 = clor72.val.v->elt[1];
    r66 = clo73(env74, r71);
    struct scm clor76;
    clor76 = scm_wrap_fptr(scm_print);
    r75 = scm_string_to_vector("\n");
    scm_fptr clo77;
    struct scm env78;
    clo77 = clor76.val.v->elt[0].val.f;
    env78 = clor76.val.v->elt[1];
    r67 = clo77(env78, r75);
    scm_fptr clo69;
    struct scm env70;
    clo69 = clor68.val.v->elt[0].val.f;
    env70 = clor68.val.v->elt[1];
    r65 = clo69(env70, r66, r67);
    return r65;
}

struct scm do_times(struct scm env2498, struct scm n, struct scm state) { BLURT;
    struct scm r79;
    struct scm r80;
    struct scm r81;
    struct scm r85;
    struct scm r89;
    struct scm r90;
    struct scm r91;
    struct scm r95;
    struct scm r96;
    struct scm r100;
    struct scm r101;
    struct scm r105;
    struct scm r106;
    struct scm r113;
    struct scm r114;
    struct scm clor82;
    clor82 = scm_wrap_fptr(begin);
    struct scm clor86;
    clor86 = scm_wrap_fptr(print_line);
    r85 = state;
    scm_fptr clo87;
    struct scm env88;
    clo87 = clor86.val.v->elt[0].val.f;
    env88 = clor86.val.v->elt[1];
    r80 = clo87(env88, r85);
    struct scm clor92;
    clor92 = scm_wrap_fptr(scm_eq);
    r90 = n;
    r91 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo93;
    struct scm env94;
    clo93 = clor92.val.v->elt[0].val.f;
    env94 = clor92.val.v->elt[1];
    r89 = clo93(env94, r90, r91);
    if (scm_extract_truth(r89)) {
        r81 = (struct scm){ .tag = 0, .val.i = 0 };
    } else {
        struct scm clor97;
        clor97 = scm_wrap_fptr(do_times);
        struct scm clor102;
        clor102 = scm_wrap_fptr(scm_minus);
        r100 = n;
        r101 = (struct scm){ .tag = 0, .val.i = 1 };
        scm_fptr clo103;
        struct scm env104;
        clo103 = clor102.val.v->elt[0].val.f;
        env104 = clor102.val.v->elt[1];
        r95 = clo103(env104, r100, r101);
        struct scm clor107;
        clor107 = scm_wrap_fptr(scm_make_vector);
        struct scm clor110;
        clor110 = scm_wrap_fptr(size);
        scm_fptr clo111;
        struct scm env112;
        clo111 = clor110.val.v->elt[0].val.f;
        env112 = clor110.val.v->elt[1];
        r105 = clo111(env112);
        struct scm clor115;
        clor115 = scm_wrap_fptr(next);
        r113 = state;
        struct scm clor118;
        clor118 = scm_wrap_fptr(size);
        scm_fptr clo119;
        struct scm env120;
        clo119 = clor118.val.v->elt[0].val.f;
        env120 = clor118.val.v->elt[1];
        r114 = clo119(env120);
        scm_fptr clo116;
        struct scm env117;
        //printf(" %d %d %d ---\n", clor115.tag, clor115.val.v->elt[0].tag, clor115.val.v->elt[1].tag);
        clo116 = clor115.val.v->elt[0].val.f;
        env117 = clor115.val.v->elt[1];
        r106 = clo116(env117, r113, r114);
        scm_fptr clo108;
        struct scm env109;
        clo108 = clor107.val.v->elt[0].val.f;
        env109 = clor107.val.v->elt[1];
        r96 = clo108(env109, r105, r106);
        scm_fptr clo98;
        struct scm env99;
        clo98 = clor97.val.v->elt[0].val.f;
        env99 = clor97.val.v->elt[1];
        r81 = clo98(env99, r95, r96);
    }
    scm_fptr clo83;
    struct scm env84;
    clo83 = clor82.val.v->elt[0].val.f;
    env84 = clor82.val.v->elt[1];
    r79 = clo83(env84, r80, r81);
    return r79;
}

struct scm scm_main(struct scm env2498) { BLURT;
    struct scm r121;
    struct scm r122;
    struct scm r123;
    struct scm clor124;
    clor124 = scm_wrap_fptr(do_times);
    struct scm clor127;
    clor127 = scm_wrap_fptr(size);
    scm_fptr clo128;
    struct scm env129;
    clo128 = clor127.val.v->elt[0].val.f;
    env129 = clor127.val.v->elt[1];
    r122 = clo128(env129);
    struct scm clor130;
    clor130 = scm_wrap_fptr(initial_condition);
    scm_fptr clo131;
    struct scm env132;
    clo131 = clor130.val.v->elt[0].val.f;
    env132 = clor130.val.v->elt[1];
    r123 = clo131(env132);
    scm_fptr clo125;
    struct scm env126;
    clo125 = clor124.val.v->elt[0].val.f;
    env126 = clor124.val.v->elt[1];
    r121 = clo125(env126, r122, r123);
    return r121;
}

struct scm g2500(struct scm env2498, struct scm i) { BLURT;
    struct scm r133;
    struct scm r134;
    struct scm r135;
    struct scm r136;
    struct scm r140;
    struct scm r141;
    struct scm clor137;
    clor137 = scm_wrap_fptr(scm_eq);
    r135 = i;
    struct scm clor142;
    clor142 = scm_wrap_fptr(scm_divide);
    struct scm clor145;
    clor145 = scm_wrap_fptr(size);
    scm_fptr clo146;
    struct scm env147;
    clo146 = clor145.val.v->elt[0].val.f;
    env147 = clor145.val.v->elt[1];
    r140 = clo146(env147);
    r141 = (struct scm){ .tag = 0, .val.i = 2 };
    scm_fptr clo143;
    struct scm env144;
    clo143 = clor142.val.v->elt[0].val.f;
    env144 = clor142.val.v->elt[1];
    r136 = clo143(env144, r140, r141);
    scm_fptr clo138;
    struct scm env139;
    clo138 = clor137.val.v->elt[0].val.f;
    env139 = clor137.val.v->elt[1];
    r134 = clo138(env139, r135, r136);
    if (scm_extract_truth(r134)) {
        struct scm clor148;
        clor148 = scm_wrap_fptr(hash);
        scm_fptr clo149;
        struct scm env150;
        clo149 = clor148.val.v->elt[0].val.f;
        env150 = clor148.val.v->elt[1];
        r133 = clo149(env150);
    } else {
        struct scm clor151;
        clor151 = scm_wrap_fptr(space);
        scm_fptr clo152;
        struct scm env153;
        clo152 = clor151.val.v->elt[0].val.f;
        env153 = clor151.val.v->elt[1];
        r133 = clo152(env153);
    }
    return r133;
}

struct scm g2499(struct scm env2498, struct scm i) { BLURT;
    struct scm r154;
    struct scm r155;
    struct scm r156;
    struct scm r157;
    struct scm r161;
    struct scm r162;
    struct scm r163;
    struct scm r167;
    struct scm r171;
    struct scm r172;
    struct scm r176;
    struct scm r177;
    struct scm r178;
    struct scm r179;
    struct scm r180;
    struct scm r184;
    struct scm r188;
    struct scm r189;
    struct scm r193;
    struct scm r194;
    struct scm r195;
    struct scm r196;
    struct scm r197;
    struct scm r198;
    struct scm r202;
    struct scm r203;
    struct scm r207;
    struct scm r208;
    struct scm r209;
    struct scm r210;
    struct scm r214;
    struct scm r215;
    struct scm r219;
    struct scm r220;
    struct scm r221;
    struct scm r222;
    struct scm r223;
    struct scm clor158;
    clor158 = scm_wrap_fptr(rule_30);
    struct scm clor164;
    clor164 = scm_wrap_fptr(scm_eq);
    r162 = i;
    r163 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo165;
    struct scm env166;
    clo165 = clor164.val.v->elt[0].val.f;
    env166 = clor164.val.v->elt[1];
    r161 = clo165(env166, r162, r163);
    if (scm_extract_truth(r161)) {
        r155 = (struct scm){ .tag = 0, .val.i = 0 };
    } else {
        struct scm clor168;
        clor168 = scm_wrap_fptr(classify);
        struct scm clor173;
        clor173 = scm_wrap_fptr(scm_vector_ref);
        r176 = (struct scm){ .tag = 0, .val.i = 0 };
        r177 = env2498;
        r178 = (struct scm){ .tag = 0, .val.i = 1 };
        r171 = scm_vector_ref(r176, r177, r178);
        struct scm clor181;
        clor181 = scm_wrap_fptr(scm_minus);
        r179 = i;
        r180 = (struct scm){ .tag = 0, .val.i = 1 };
        scm_fptr clo182;
        struct scm env183;
        clo182 = clor181.val.v->elt[0].val.f;
        env183 = clor181.val.v->elt[1];
        r172 = clo182(env183, r179, r180);
        scm_fptr clo174;
        struct scm env175;
        clo174 = clor173.val.v->elt[0].val.f;
        env175 = clor173.val.v->elt[1];
        r167 = clo174(env175, r171, r172);
        scm_fptr clo169;
        struct scm env170;
        clo169 = clor168.val.v->elt[0].val.f;
        env170 = clor168.val.v->elt[1];
        r155 = clo169(env170, r167);
    }
    struct scm clor185;
    clor185 = scm_wrap_fptr(classify);
    struct scm clor190;
    clor190 = scm_wrap_fptr(scm_vector_ref);
    r193 = (struct scm){ .tag = 0, .val.i = 0 };
    r194 = env2498;
    r195 = (struct scm){ .tag = 0, .val.i = 1 };
    r188 = scm_vector_ref(r193, r194, r195);
    r189 = i;
    scm_fptr clo191;
    struct scm env192;
    clo191 = clor190.val.v->elt[0].val.f;
    env192 = clor190.val.v->elt[1];
    r184 = clo191(env192, r188, r189);
    scm_fptr clo186;
    struct scm env187;
    clo186 = clor185.val.v->elt[0].val.f;
    env187 = clor185.val.v->elt[1];
    r156 = clo186(env187, r184);
    struct scm clor199;
    clor199 = scm_wrap_fptr(scm_eq);
    r197 = i;
    struct scm clor204;
    clor204 = scm_wrap_fptr(scm_minus);
    r207 = (struct scm){ .tag = 0, .val.i = 0 };
    r208 = env2498;
    r209 = (struct scm){ .tag = 0, .val.i = 0 };
    r202 = scm_vector_ref(r207, r208, r209);
    r203 = (struct scm){ .tag = 0, .val.i = 1 };
    scm_fptr clo205;
    struct scm env206;
    clo205 = clor204.val.v->elt[0].val.f;
    env206 = clor204.val.v->elt[1];
    r198 = clo205(env206, r202, r203);
    scm_fptr clo200;
    struct scm env201;
    clo200 = clor199.val.v->elt[0].val.f;
    env201 = clor199.val.v->elt[1];
    r196 = clo200(env201, r197, r198);
    if (scm_extract_truth(r196)) {
        r157 = (struct scm){ .tag = 0, .val.i = 0 };
    } else {
        struct scm clor211;
        clor211 = scm_wrap_fptr(classify);
        struct scm clor216;
        clor216 = scm_wrap_fptr(scm_vector_ref);
        r219 = (struct scm){ .tag = 0, .val.i = 0 };
        r220 = env2498;
        r221 = (struct scm){ .tag = 0, .val.i = 1 };
        r214 = scm_vector_ref(r219, r220, r221);
        struct scm clor224;
        clor224 = scm_wrap_fptr(scm_plus);
        r222 = i;
        r223 = (struct scm){ .tag = 0, .val.i = 1 };
        scm_fptr clo225;
        struct scm env226;
        clo225 = clor224.val.v->elt[0].val.f;
        env226 = clor224.val.v->elt[1];
        r215 = clo225(env226, r222, r223);
        scm_fptr clo217;
        struct scm env218;
        clo217 = clor216.val.v->elt[0].val.f;
        env218 = clor216.val.v->elt[1];
        r210 = clo217(env218, r214, r215);
        scm_fptr clo212;
        struct scm env213;
        clo212 = clor211.val.v->elt[0].val.f;
        env213 = clor211.val.v->elt[1];
        r157 = clo212(env213, r210);
    }
    scm_fptr clo159;
    struct scm env160;
    clo159 = clor158.val.v->elt[0].val.f;
    env160 = clor158.val.v->elt[1];
    r154 = clo159(env160, r155, r156, r157);
    return r154;
}

