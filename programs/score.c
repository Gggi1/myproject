#include <stdio.h>
#include <stdlib.h>


struct student
{
    int age;
    char name[100];
    float score;
};

int input_student_info(struct student *stu_info, int len)
{
    int i;


    for (i = 0;i < len;i++)
    {
        printf("请输入第%d个学生的成绩信息：\n", i + 1);
        printf("年龄:  ");
        scanf("%d", &stu_info[i].age);
        printf("姓名:  ");
        scanf("%s", stu_info[i].name);
        printf("成绩:  ");
        scanf("%f", &stu_info[i].score);
    }
    printf("\n\n\n\n");

    return 0;
}

int output_student_info(struct student *stu_info, int len)
{
    int i;

    printf("==========成绩单==========\n\n\n\n");
    for (i = 0;i < len;i++)
    {
        printf("排名： %d\t", i + 1);
        printf("年龄:  %d\t", stu_info[i].age);
        printf("姓名:  %s\t", stu_info[i].name);
        printf("成绩:  %f\n", stu_info[i].score);
    }

    return 0;
}

int sort_student_score(struct student *stu_info, int len)
{
    int i, j;
    struct student t_info;


    for (i = 0;i < len - 1;i++)
    {
        for (j = 0;j < len - 1 - i;j++)
        {
            if (stu_info[j].score < stu_info[j + 1].score)
            {
                t_info = stu_info[j];
                stu_info[j] = stu_info[j + 1];
                stu_info[j + 1] = t_info;
            }
        }
    }
    


    return 0;
}


int main()
{
    int len;
    struct student *stu_info = (struct student *)malloc(len * sizeof(struct student));


    printf("==========欢迎使用学生成绩信息录入系统==========\n");
    printf("请输入学生数:  \n");
    scanf("%d", &len);
    printf("学生  共%d人\n", len);
    input_student_info(stu_info, len);
    sort_student_score(stu_info, len);
    output_student_info(stu_info, len);
    free(stu_info);
    printf("==========期待与您再会==========\n");


    return 0;
}
