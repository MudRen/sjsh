 // inittask.c    bombju

int main()
{
remove_call_out("init_dynamic_quest");
  TASK_D->init_dynamic_quest(1);
    write("����ϵͳ TASK ���!\n");
  return 1;

}

int help(object me)
{
     write("ָ���ʽ: inittask\n\n");
write("���ָ������ǿ�Ƹ���ϵͳ TASK\n");
   return 1;
}

