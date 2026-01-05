#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_FILE "rules.json"

// 生成变化的 IP 地址
void generate_ip(char *ip_buffer, int base_ip, int index) {
    int ip1 = (base_ip >> 24) & 0xFF;  // 固定为 10
    int ip2 = (base_ip >> 16) & 0xFF;  // 固定为 0
    int ip3 = (index / 256) & 0xFF;    // 变化的第三段 (X 位)
    int ip4 = (index % 256) & 0xFF;    // 变化的第四段 (Y 位)
    sprintf(ip_buffer, "%d.%d.%d.%d", ip1, ip2, ip3, ip4);
}

int main() {
    int start_rule_id, total_rules;

    // 用户输入起始 rule_id 和总规则数量
    printf("请输入起始 rule_id: ");
    scanf("%d", &start_rule_id);
    printf("请输入总规则数量: ");
    scanf("%d", &total_rules);

    FILE *fp = fopen(OUTPUT_FILE, "w");

    if (fp == NULL) {
        printf("无法创建文件 %s\n", OUTPUT_FILE);
        return 1;
    }

    // 写入 JSON 文件开头
    fprintf(fp, "{\n");
    fprintf(fp, "    \"rulelistunit\": [\n");

    int base_sip = 0x0A000000;  // 10.0.0.0
    int base_dip = 0x0A000000;  // 10.0.0.0

    // 生成规则列表
    for (int i = 0; i < total_rules; i++) {
        int rule_id = start_rule_id + i;
        char sip[16], dip[16];

        // 生成变化的 sip 和 dip
        generate_ip(sip, base_sip, i);
        generate_ip(dip, base_dip, i + 1);

        // 随机选择 sip_mask 和 dip_mask
        const char *sip_mask = (i % 2 == 0) ? "255.255.255.0" : "255.255.0.0";
        const char *dip_mask = (i % 2 == 0) ? "255.255.255.0" : "255.255.0.0";

        // 写入每条规则
        fprintf(fp,
                "        {\n"
                "            \"rule_id\": %d,\n"
                "            \"inputgroup_id\": 1,\n"
                "            \"outputgroup_id\": 2,\n"
                "            \"rule_type\": 3,\n"
                "            \"ip_in_out\": 0,\n"
                "            \"ip_version\": 4,\n"
                "            \"sip\": \"%s\",\n"
                "            \"sip_mask\": \"%s\",\n"
                "            \"dip\": \"%s\",\n"
                "            \"dip_mask\": \"%s\",\n"
                "            \"sport\": \"443\",\n"
                "            \"sport_mask\": \"0xffff\",\n"
                "            \"dport\": \"49384\",\n"
                "            \"dport_mask\": \"0xffff\",\n"
                "            \"protocol\": \"TCP\",\n"
                "            \"action_type_list\": [2],\n"
                "            \"copygroup_list\": 7\n"
                "        }%s\n",
                rule_id,
                sip,
                sip_mask,
                dip,
                dip_mask,
                (i == total_rules - 1) ? "" : ","  // 最后一条规则后面不加逗号
        );
    }

    // 写入 JSON 文件结尾
    fprintf(fp, "    ]\n");
    fprintf(fp, "}\n");

    fclose(fp);
    printf("规则文件 %s 生成成功，包含 %d 条规则。\n", OUTPUT_FILE, total_rules);
    return 0;
}

