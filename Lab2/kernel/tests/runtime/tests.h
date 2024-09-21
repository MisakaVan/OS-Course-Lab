/*
 * Copyright (c) 2023 Institute of Parallel And Distributed Systems (IPADS), Shanghai Jiao Tong University (SJTU)
 * Licensed under the Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *     http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
 * PURPOSE.
 * See the Mulan PSL v2 for more details.
 */

#ifndef KERNEL_TESTS_RUNTIME_TESTS_H
#define KERNEL_TESTS_RUNTIME_TESTS_H

#define TEST_SUITE(lab, name) void lab##_##name(void)
#define TEST(name)                           \
        for (const char *test_name = (name); \
             printk("[TEST] %s: OK\n", test_name),0;)
#define ASSERT(expr)                                                       \
        do {                                                               \
                if (!(expr))                                               \
                                                                           \
                {                                                          \
                        printk("[TEST] %s: FAIL, loc: %s: %d, expr: %s\n", \
                               test_name,                                  \
                               __FILE__,                                   \
                               __LINE__,                                   \
                               #expr);                                     \
                }                                                          \
        } while (0)
#endif /* KERNEL_TESTS_RUNTIME_TESTS_H */
