
#include <ruby.h>
#include <wchar.h>
#include <ruby/encoding.h>

#define MIN(x ,y) ({\
  __typeof__ (x) _x = (x);\
  __typeof__ (y) _y = (y);\
  _x < _y ? _x : _y; })

VALUE Levenshtein = Qnil;

void Init_levenshtein();
VALUE method_levenshtein_distance(VALUE self, VALUE word1, VALUE word2);

void Init_levenshtein() {
  Levenshtein = rb_define_module("Levenshtein");
  rb_define_singleton_method(Levenshtein, "distance", method_levenshtein_distance, 2);
}

VALUE method_levenshtein_distance(VALUE self, VALUE word1, VALUE word2) {
  rb_encoding *enc = rb_enc_find("UTF-32BE");
  VALUE w1_enc  =  rb_str_export_to_enc(word1, enc), \
    w2_enc  =  rb_str_export_to_enc(word2, enc);

  wchar_t *w1 = RSTRING_PTR(w1_enc), *w2 = RSTRING_PTR(w2_enc);
  size_t l1 = wcslen(w1), l2 = wcslen(w2);

  unsigned int j, cost, cur, i = 0, next = 0;
  unsigned int *d = malloc((l2 + 1) * 4);

  while (l1 > 0 && l2 > 0 && w1[0] == w2[0])
    w1++, w2++, l1--, l2--;

  if (l1 == 0 || l2 == 0)
    return l1 == 0 ? UINT2NUM(l2) : UINT2NUM(l1);

  for (j = 0; j < l2+1; j++)
    d[j] = j;

  while(i < l1) {
    cur = i + 1;
    for (j = 0; j < l2; j++) {
      cost = !((w1[i] == w2[j]) || (i && j && (w1[i-1] == w2[j]) && (w1[i] == w2[j-1])));
      next = MIN(MIN(d[j+1] + 1, cur+ 1), d[j] + cost);
      d[j] = cur;
      cur = next;
    }
    d[l2] = next;
    i++;
  }
  free(d);
  return UINT2NUM(next);
}
