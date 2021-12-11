#include "bistromatic.h"
#include "exp.h"
#include <stdlib.h>
#include <stdio.h>

#define LN_2 "0.6931471805599453094172321214581765680755001343602552541206800094933936219696947156058633269964186875420014810205706857336855202"
#define LN_10 "2.3025850929940456840179914546843642076011014886287729760333279009675726096773524802359972050895982983419677840422862486334095254650828067566662873690987816894829072083255546808437998948262331985283935053089653777326288461633662222876982198867465436674"

char *new_ln(char *x)
{
    if (my_strstr(x, "1"))
        return my_strdup("0");
    int n = my_strlen(x) - nb_decimals(x, OPS) - 1;
    int index_dot = index_of('.', x);
    char *a = my_strdup(x);
    int to_free = 0;
    char *a_minus;
    char *a_plus;
    char *y;
    char *coefs[51] = {
        "1",
        "0.3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333",
        "0.2",
        "0.1428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428",
        "0.1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
        "0.0909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909",
        "0.0769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769",
        "0.0666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666",
        "0.0588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294",
        "0.0526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684",
        "0.0476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476",
        "0.0434782608695652173913043478260869565217391304347826086956521739130434782608695652173913043478260869565217391304347826086956521739130434782608695652173913043478260869565217391304347826086956521739130434782608695652173913043478260869565217391304347826",
        "0.04",
        "0.0370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370",
        "0.0344827586206896551724137931034482758620689655172413793103448275862068965517241379310344827586206896551724137931034482758620689655172413793103448275862068965517241379310344827586206896551724137931034482758620689655172413793103448275862068965517241379",
        "0.0322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645",
        "0.0303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303",
        "0.0285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285",
        "0.0270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270",
        "0.0256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256",
        "0.0243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439",
        "0.0232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720",
        "0.0222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222",
        "0.0212765957446808510638297872340425531914893617021276595744680851063829787234042553191489361702127659574468085106382978723404255319148936170212765957446808510638297872340425531914893617021276595744680851063829787234042553191489361702127659574468085106",
        "0.0204081632653061224489795918367346938775510204081632653061224489795918367346938775510204081632653061224489795918367346938775510204081632653061224489795918367346938775510204081632653061224489795918367346938775510204081632653061224489795918367346938775",
        "0.0196078431372549019607843137254901960784313725490196078431372549019607843137254901960784313725490196078431372549019607843137254901960784313725490196078431372549019607843137254901960784313725490196078431372549019607843137254901960784313725490196078431",
        "0.0188679245283018867924528301886792452830188679245283018867924528301886792452830188679245283018867924528301886792452830188679245283018867924528301886792452830188679245283018867924528301886792452830188679245283018867924528301886792452830188679245283018",
        "0.0181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181",
        "0.0175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228",
        "0.0169491525423728813559322033898305084745762711864406779661016949152542372881355932203389830508474576271186440677966101694915254237288135593220338983050847457627118644067796610169491525423728813559322033898305084745762711864406779661016949152542372881",
        "0.0163934426229508196721311475409836065573770491803278688524590163934426229508196721311475409836065573770491803278688524590163934426229508196721311475409836065573770491803278688524590163934426229508196721311475409836065573770491803278688524590163934426",
        "0.0158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158",
        "0.0153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153",
        "0.0149253731343283582089552238805970149253731343283582089552238805970149253731343283582089552238805970149253731343283582089552238805970149253731343283582089552238805970149253731343283582089552238805970149253731343283582089552238805970149253731343283582",
        "0.0144927536231884057971014492753623188405797101449275362318840579710144927536231884057971014492753623188405797101449275362318840579710144927536231884057971014492753623188405797101449275362318840579710144927536231884057971014492753623188405797101449275",
        "0.0140845070422535211267605633802816901408450704225352112676056338028169014084507042253521126760563380281690140845070422535211267605633802816901408450704225352112676056338028169014084507042253521126760563380281690140845070422535211267605633802816901408",
        "0.0136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301",
        "0.0133333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333",
        "0.0129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129",
        "0.0126582278481012658227848101265822784810126582278481012658227848101265822784810126582278481012658227848101265822784810126582278481012658227848101265822784810126582278481012658227848101265822784810126582278481012658227848101265822784810126582278481012",
        "0.0123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456",
        "0.0120481927710843373493975903614457831325301204819277108433734939759036144578313253012048192771084337349397590361445783132530120481927710843373493975903614457831325301204819277108433734939759036144578313253012048192771084337349397590361445783132530120",
        "0.0117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058",
        "0.0114942528735632183908045977011494252873563218390804597701149425287356321839080459770114942528735632183908045977011494252873563218390804597701149425287356321839080459770114942528735632183908045977011494252873563218390804597701149425287356321839080459",
        "0.0112359550561797752808988764044943820224719101123595505617977528089887640449438202247191011235955056179775280898876404494382022471910112359550561797752808988764044943820224719101123595505617977528089887640449438202247191011235955056179775280898876404",
        "0.0109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109",
        "0.0107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881",
        "0.0105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736",
        "0.0103092783505154639175257731958762886597938144329896907216494845360824742268041237113402061855670103092783505154639175257731958762886597938144329896907216494845360824742268041237113402061855670103092783505154639175257731958762886597938144329896907216",
        "0.0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101",
        0};
    char *impairs[51] = {"1", "3", "5", "7", "9", "11", "13", "15", "17", "19", "21", "23", "25", "27", "29", "31", "33", "35", "37", "39", "41", "43", "45", "47", "49", "51", "53", "55", "57", "59", "61", "63", "65", "67", "69", "71", "73", "75", "77", "79", "81", "83", "85", "87", "89", "91", "93", "95", "97", "99", 0};
    char *pow_y;
    char *tmp_div;
    char *s_p = my_strdup("0");
    char *str_n_minus_one;
    char *n_log_10;
    char *result;

    if (index_dot >= 0) {
        a = replace(x, index_dot, 1, "");
        to_free = 1;
    }
    re_alloc(&a, replace(a, 1, 0, "."), to_free);
    a_minus = infin_sub(a, "1", BASE, OPS);
    a_plus = infin_add(a, "1", BASE, OPS);
    y = infin_div(a_minus, a_plus, BASE, OPS);
    for (int i = 0; coefs[i]; i++) {
        pow_y = my_pow(y, impairs[i], BASE, OPS);
        tmp_div = infin_div(pow_y, impairs[i], BASE, OPS);
        re_alloc(&s_p, infin_add(s_p, tmp_div, BASE, OPS), 1);
        free(pow_y);
        free(tmp_div);
    }
    re_alloc(&s_p, infin_mul("2", s_p, BASE, OPS), 1);
    int_to_str(n - 1, &str_n_minus_one);
    n_log_10 = infin_mul(str_n_minus_one, LN_10, BASE, OPS);
    result = infin_add(n_log_10, s_p, BASE, OPS);
    free(a);
    free(a_plus);
    free(a_minus);
    free(y);
    free(s_p);
    free(str_n_minus_one);
    free(n_log_10);
    return result;
}

char *ln_small(char *x)
{
    char *coefs[100] = {
    "1",
    "-0.5",
    "0.3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333",
    "-0.25",
    "0.2",
    "-0.1666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666",
    "0.1428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428",
    "-0.125",
    "0.1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
    "-0.1",
    "0.0909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909090909",
    "-0.0833333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333",
    "0.0769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769230769",
    "-0.0714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714",
    "0.0666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666",
    "-0.0625",
    "0.0588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294",
    "-0.0555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555",
    "0.0526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684210526315789473684",
    "-0.05",
    "0.0476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476190476",
    "-0.0454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454545454",
    "0.0434782608695652173913043478260869565217391304347826086956521739130434782608695652173913043478260869565217391304347826086956521739130434782608695652173913043478260869565217391304347826086956521739130434782608695652173913043478260869565217391304347826",
    "-0.0416666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666",
    "0.04",
    "-0.0384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384615384",
    "0.0370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370370",
    "-0.0357142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857",
    "0.0344827586206896551724137931034482758620689655172413793103448275862068965517241379310344827586206896551724137931034482758620689655172413793103448275862068965517241379310344827586206896551724137931034482758620689655172413793103448275862068965517241379",
    "-0.0333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333",
    "0.0322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645",
    "-0.03125",
    "0.0303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303030303",
    "-0.0294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647",
    "0.0285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285714285",
    "-0.0277777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777",
    "0.0270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270270",
    "-0.0263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842",
    "0.0256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256410256",
    "-0.025",
    "0.0243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439024390243902439",
    "-0.0238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238095238",
    "0.0232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720930232558139534883720",
    "-0.0227272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727272727",
    "0.0222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222",
    "-0.0217391304347826086956521739130434782608695652173913043478260869565217391304347826086956521739130434782608695652173913043478260869565217391304347826086956521739130434782608695652173913043478260869565217391304347826086956521739130434782608695652173913",
    "0.0212765957446808510638297872340425531914893617021276595744680851063829787234042553191489361702127659574468085106382978723404255319148936170212765957446808510638297872340425531914893617021276595744680851063829787234042553191489361702127659574468085106",
    "-0.0208333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333",
    "0.0204081632653061224489795918367346938775510204081632653061224489795918367346938775510204081632653061224489795918367346938775510204081632653061224489795918367346938775510204081632653061224489795918367346938775510204081632653061224489795918367346938775",
    "-0.02",
    "0.0196078431372549019607843137254901960784313725490196078431372549019607843137254901960784313725490196078431372549019607843137254901960784313725490196078431372549019607843137254901960784313725490196078431372549019607843137254901960784313725490196078431",
    "-0.0192307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692307692",
    "0.0188679245283018867924528301886792452830188679245283018867924528301886792452830188679245283018867924528301886792452830188679245283018867924528301886792452830188679245283018867924528301886792452830188679245283018867924528301886792452830188679245283018",
    "-0.0185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185185",
    "0.0181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181818181",
    "-0.0178571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428571428",
    "0.0175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228070175438596491228",
    "-0.0172413793103448275862068965517241379310344827586206896551724137931034482758620689655172413793103448275862068965517241379310344827586206896551724137931034482758620689655172413793103448275862068965517241379310344827586206896551724137931034482758620689",
    "0.0169491525423728813559322033898305084745762711864406779661016949152542372881355932203389830508474576271186440677966101694915254237288135593220338983050847457627118644067796610169491525423728813559322033898305084745762711864406779661016949152542372881",
    "-0.0166666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666",
    "0.0163934426229508196721311475409836065573770491803278688524590163934426229508196721311475409836065573770491803278688524590163934426229508196721311475409836065573770491803278688524590163934426229508196721311475409836065573770491803278688524590163934426",
    "-0.0161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322580645161290322",
    "0.0158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158730158",
    "-0.015625",
    "0.0153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153846153",
    "-0.0151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151515151",
    "0.0149253731343283582089552238805970149253731343283582089552238805970149253731343283582089552238805970149253731343283582089552238805970149253731343283582089552238805970149253731343283582089552238805970149253731343283582089552238805970149253731343283582",
    "-0.0147058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823",
    "0.0144927536231884057971014492753623188405797101449275362318840579710144927536231884057971014492753623188405797101449275362318840579710144927536231884057971014492753623188405797101449275362318840579710144927536231884057971014492753623188405797101449275",
    "-0.0142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142857142",
    "0.0140845070422535211267605633802816901408450704225352112676056338028169014084507042253521126760563380281690140845070422535211267605633802816901408450704225352112676056338028169014084507042253521126760563380281690140845070422535211267605633802816901408",
    "-0.0138888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888",
    "0.0136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301369863013698630136986301",
    "-0.0135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135135",
    "0.0133333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333",
    "-0.0131578947368421052631578947368421052631578947368421052631578947368421052631578947368421052631578947368421052631578947368421052631578947368421052631578947368421052631578947368421052631578947368421052631578947368421052631578947368421052631578947368421",
    "0.0129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129870129",
    "-0.012820512820512820512820512820512820512820512820512820512820512820512820512820512820512820512820512820512820512820512820512820512820512820512820512820",
    "0.0126582278481012658227848101265822784810126582278481012658227848101265822784810126582278481012658227848101265822784810126582278481012658227848101265822",
    "-0.0125",
    "0.0123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456790123456",
    "-0.012195121951219512195121951219512195121951219512195121951219512195121951219512195121951219512195121951219512195121951219512195121951219512195121951219",
    "0.0120481927710843373493975903614457831325301204819277108433734939759036144578313253012048192771084337349397590361445783132530120481927710843373493975903",
    "-0.011904761904761904761904761904761904761904761904761904761904761904761904761904761904761904761904761904761904761904761904761904761904761904761904761904",
    "0.0117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647058823529411764705882352941176470588235294117647",
    "-0.011627906976744186046511627906976744186046511627906976744186046511627906976744186046511627906976744186046511627906976744186046511627906976744186046511",
    "0.0114942528735632183908045977011494252873563218390804597701149425287356321839080459770114942528735632183908045977011494252873563218390804597701149425287",
    "-0.011363636363636363636363636363636363636363636363636363636363636363636363636363636363636363636363636363636363636363636363636363636363636363636363636363",
    "0.0112359550561797752808988764044943820224719101123595505617977528089887640449438202247191011235955056179775280898876404494382022471910112359550561797752",
    "-0.011111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
    "0.0109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890109890",
    "-0.010869565217391304347826086956521739130434782608695652173913043478260869565217391304347826086956521739130434782608695652173913043478260869565217391304",
    "0.0107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430107526881720430",
    "-0.010638297872340425531914893617021276595744680851063829787234042553191489361702127659574468085106382978723404255319148936170212765957446808510638297872",
    "0.0105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263157894736842105263",
    "-0.010416666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666",
    "0.0103092783505154639175257731958762886597938144329896907216494845360824742268041237113402061855670103092783505154639175257731958762886597938144329896907",
    "-0.010204081632653061224489795918367346938775510204081632653061224489795918367346938775510204081632653061224489795918367346938775510204081632653061224489",
    "0.0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010",
    0};
    char *x_minus_one = infin_sub(my_strdup(x), my_strdup("1"), BASE, OPS);
    char *x_minus_one_pow_n;
    char *n;
    char *tmp;
    char *result = my_strdup("0");

    for (int i = 1; i < 50; i++) {
        int_to_str(i, &n);
        x_minus_one_pow_n = my_pow(x_minus_one, n, BASE, OPS);
        tmp = infin_mul(coefs[i - 1], x_minus_one_pow_n, BASE, OPS);
        re_alloc(&result, infin_add(result, tmp, BASE, OPS), 1);
    }
    return result;
}

int compare_point(char *first, char *second)
{
    int i;

    for (i = 0; first[i] && second[i]; i++) {
        if (first[i] != second[i])
            return first[i] - second[i];
    }
    return first[i] - second[i];
}

char *my_ln (char *x)
{
    int m;
    char *k = my_strdup(x);
    char *two = my_strdup("2");
    char *ln_k;
    char *str_m;
    char *m_ln_2;
    char *result;

    for (m = 0; compare_point(k, "1.3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333") > 0; m++)
        re_alloc(&k, infin_div(k, two, BASE, OPS), 1);
    ln_k = ln_small(k);
    int_to_str(m, &str_m);
    m_ln_2 = infin_mul(LN_2, str_m, BASE, OPS);
    result = infin_add(ln_k, m_ln_2, BASE, OPS);
    free(k);
    free(two);
    free(ln_k);
    free(str_m);
    free(m_ln_2);
    return result;
}