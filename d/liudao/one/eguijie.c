//By Repoo and Xuexu
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short", HIG"�����"NOR);
set("long", @LONG
  
    ����������֮�еĶ���磬Ҳ������������ѵ��ֻ����磬���������ŵ�����
�Ļ��档�ڻ����г����ű�������ĥ�Ķ���ĲҽУ��������г����Ÿ����������
ǿ��Ը����
  
LONG );
     set("exits/east", __DIR__"eguijie"+(string)random(8));
     set("exits/west", __DIR__"eguijie"+(string)random(8));
     set("exits/south", __DIR__"eguijie"+(string)random(8));
     set("exits/north", __DIR__"eguijie"+(string)random(8));
     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/egui" : 1,
]));
setup();
}
void init() 
{
              int i;
        object* inv;
        object me = this_object();
             delete("exits/out");
     if(this_player()->query_temp("liudao/eguijie_kill") >= 64)
    {
message_vision(HIR"\n$N��ǰһ�죬��ǰ������һ��ټ��ĳ��ڣ��������������ƺ����ſ��µ�Ԥ�С�\n\n"NOR,this_player());
           set("exits/out", __DIR__"shenpanshi");
     } 
   if (this_player()->query_temp("liudao/eguijie") == "begin")
    {
    remove_call_out ("check_hp");
     call_out ("check_hp", 1,this_player());
    }
        inv = all_inventory(this_player());
        for(i=0; i<sizeof(inv); i++) 
        {
                if( inv[i]->query_unique() ) {
message_vision(HIW"ͻȻ�䣬$n��һ���׹��ȥ����Ӱ���٣�\n"NOR,me,inv[i]);
                        destruct(inv[i]);
                                                                    }
        }
   add_action ("do_cast","cast");
}
int check_hp(object who)
     {
  object where = this_object();
  if ( (! who)  ||    (! present(who, where)) )  return 1;
   if (random(4)==1 && who->query("sen") > 50 )
    {
      who->add("sen",-(100+random(50)));
     message_vision(HIR"ͻȻ�������һ˫���õ��֣�������������˺����Ƭ��\n"NOR,who);
     COMBAT_D->report_sen_status(who);
    }
  if ( (100*(who->query("kee")))/(who->query("max_kee")) <= 10)
    {
     message_vision(HIR"��챻��˫���õ�����ô����������ˡ�\n"NOR,who);
     who->delete_temp("last_damage_from");
who->set_temp("death_msg", "�ڶ���类����˺������Ƭ��\n");
     who->die();
     who->save();
     return 1;
    }
  remove_call_out ("check_hp");
  call_out ("check_hp", 1,who);
  return 1;
    }
int do_cast (string arg)
{
  object who = this_player();
  if (who->query_temp("liudao/eguijie")=="begin" && 
             (arg=="escape" || arg=="shuidun" || arg=="tudun"))
     {
      tell_object(who,"���ﲻ��������\n");
      return 1;
     }
  else return 0;
}
