#include <check.h>

#include "../code_on_c/parser.h"

START_TEST(test_isNum) {
    char symbol1 = 'r';

    int result = isNum(symbol1) == 0;  

    ck_assert_int_eq(result, 1);
} END_TEST

START_TEST(test_getData) {
    char *filename = calloc(100, sizeof(char));
    strcpy(filename, "./objFiles/cube.obj" );
    vertex_index_st *data = getData(filename);
    unsigned arrIndexRes[] = {1, 2, 2, 3, 3, 1, 7, 6, 6, 5, 5, 7, 4, 5, 5, 1, 1, 4, 5, 6, 6, 2, 2, 5, 2, 6, 6, 7, 7, 2, 0, 3, 3, 7, 7, 0, 0, 1, 1, 3, 3, 0, 4, 7, 7, 5, 5, 4, 0, 4, 4, 1, 1, 0, 1, 5, 5, 2, 2, 1, 3, 2, 2, 7, 7, 3, 4, 0, 0, 7, 7, 4};
    double arrVertexRes[] = {0.500000, -0.500000, -0.500000, 0.500000, -0.500000, 0.500000, -0.500000, -0.500000, 0.500000, -0.500000, -0.500000, -0.500000, 0.500000, 0.500000, -0.500000, 0.500000, 0.500000, 0.500000, -0.500000, 0.500000, 0.500000, -0.500000, 0.500000, -0.500000};
    int result = 0;
    for (int i = 0; i < data->index.memory; i++) {
      if (data->index.arr[i] != arrIndexRes[i]) result = 1;
    }
    for (int i = 0; i < data->vertex.memory; i++) {
      if (data->vertex.arr[i] != arrVertexRes[i]) result = 1;
    }
    deleteData(data);
    ck_assert_int_eq(result, 0);
    
} END_TEST

START_TEST(test_changeState) {
    char *filename = calloc(100, sizeof(char));
    strcpy(filename, "./objFiles/cube.obj" );
    double arrVertexRes[] = {-0.150080, 1.310974, -0.121047, 0.622981, 0.953562, 0.724312, 1.234496, 0.329933, -0.098570, 0.461435, 0.687345, -0.943930, -0.834496, 0.350067, 0.098570, -0.061435, -0.007345, 0.943930, 0.550080, -0.630974, 0.121047, -0.222981, -0.273562, -0.724312};
    int result = 0;
    vertex_index_st *data = getData(filename);
    state_st *state = malloc(1 * sizeof(state_st));
    state->rx = 0.4;
    state->ry = 0.7;
    state->rz = 2.3;
    state->scale = 1.2;
    state->tx = 0.2;
    state->ty = 0.34;
    stateСhange(&data->vertex, state);
    for (int i = 0; i < data->vertex.memory; i++) {
      if (fabs(fabs(data->vertex.arr[i]) - fabs(arrVertexRes[i])) > 0.0001) {
        result = 1;
      }
    }
    deleteData(data);
    ck_assert_int_eq(result, 0);
} END_TEST



int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_isNum);
  tcase_add_test(tc1_1, test_getData);
  tcase_add_test(tc1_1, test_changeState);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}