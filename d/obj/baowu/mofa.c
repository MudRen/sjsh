      inherit ITEM; 


void init()
{
              add_action("do_yell", "yell"); 
}

void create()
{
        set_name("ħ����", ({"mofa sword", "jian", "gun"})); 
        set_weight(50); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�ԹŶ�����һ���������γɵ�һ��������\n");
                set("value", 0); 
        }
        setup();
}
int do_yell(string arg)
{
object ob,me=this_player(); 
             if( !arg ) return notify_fail("�����ٻ�˭??\n"); 

             if(!(ob = LOGIN_D->find_body(arg)))
                                         return notify_fail("û������ˡ�\n"); 
             if(present(ob, environment(me)))
                                      return notify_fail("������Ѿ�������ǰ��\n"); 
             message_vision("$N�����е���"+ob->query("name")+"��������\n",me); 
             message_vision("$N��Լ�����������ٻ�$N�����ӱ㲻�������ر�һ��������������ȥ��\n",ob); 
             ob->move(environment(me)); 
             message_vision("$N������$n��ߡ�\n",ob,me); 
           return 1; 
}


