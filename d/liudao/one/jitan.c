inherit ROOM;
#include <ansi.h>
void create()
{
set("short", HIY"��"NOR+HIB"��"NOR+HIR"��̳"NOR);
set("long", @LONG

    �߽�����տ��Ĵ���������һ����̳����������ɫ����Ĺ�â�ڴ�����ҫ��
�㶨����ȥ��ԭ����̫�����������ļ�̳��

LONG);
        set("exits", 
        ([ 
                        ]));
set("objects", ([ /* sizeof() == 1*/ 
]));
setup();
}
void init()
{
int i,j;
        object* inv;
        object me = this_player();
        inv = all_inventory(this_player());
        for(i=0; i<sizeof(inv); i++) 
       {
                if( inv[i]->query("id") == "tai yang") {
message("channel:rumor",HIY+"��"+HIB" �����ֻ� "NOR+HIY"����"NOR+HIR"������ǰ�ڷ���һ���޿�������ǿ�Ұ�ɫ��â����Ŭ�������۾�\n                ����"NOR+HIY"��̫����"NOR+HIR"��ɢ���ų��ȵİ׹⣬������ǰ��������\n"+NOR,users() );
         call_out ("dest",1,inv[i]);  
               this_player()->set_temp("eguijie/sun","done");
                            }
       }
        for(j=0; j<sizeof(inv); j++) 
        {
                if( inv[j]->query("id") == "yue") {
message("channel:rumor",HIY+"��"+HIB" �����ֻ� "NOR+HIY"����"NOR+HIM"������"+HIB"��������"NOR+HIM"����һ���������ҫ�۵Ĺ�â����̫���Ա��γ�\n                һ�������ľ�ɫ��\n"+NOR,users() );
                        destruct(inv[j]);
               this_player()->set_temp("eguijie/moon","done");
                            }
       }
if(me->query_temp("eguijie/moon") == "done" && me->query_temp("eguijie/sun") == "done")
  {
            call_out ("pass",1,me);  
  }
}
void dest (object me)
{
  destruct(me);
  return;
}
void pass (object ob)
{
if (ob->query("liudao/eguijie") == "done")
return;
  ob->delete_temp("liudao/eguijie","begin");
  ob->set("liudao/eguijie","done");
  ob->add("liudao/number",1);
    ob->add("combat_exp",10000);
tell_object(ob,"��Ӯ����"+chinese_number(1)+"�����ѧ������\n");
message("channel:chat",HIY+"��"+HIB" �����ֻ� "NOR+HIY"����"NOR+ob->query("name")+HIB"˳�����������еĶ���硣\n"+NOR,users() );
  ob->move("/d/changan/fendui");
  return;
}
