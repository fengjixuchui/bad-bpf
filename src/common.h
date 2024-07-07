// SPDX-License-Identifier: BSD-3-Clause
#ifndef BAD_BPF_COMMON_H
#define BAD_BPF_COMMON_H

// These are used by a number of
// different programs to sync eBPF Tail Call
// login between user space and kernel
#define PROG_00 0
#define PROG_01 1
#define PROG_02 2

// Used when replacing text
#define FILENAME_LEN_MAX 50
#define TEXT_LEN_MAX 20
#define LOCAL_BUFF_SIZE 64
// NOTE: This should probably be a map-of-maps, with the top-level
// key bing pid_tgid, so we know we're looking at the right program
#define MAX_POSSIBLE_ADDRS 300

// Simple message structure to get events from eBPF Programs
// in the kernel to user spcae
#define TASK_COMM_LEN 16
struct event {
    int pid;
    char comm[TASK_COMM_LEN];
    bool success;
};

struct tr_file {
    char filename[FILENAME_LEN_MAX];
    unsigned int filename_len;
};

struct tr_text {
    char text[TEXT_LEN_MAX];
    unsigned int text_len;
};

#endif  // BAD_BPF_COMMON_H
