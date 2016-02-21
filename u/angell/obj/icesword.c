#include <weapon.h>
#include <ansi.h>

inherit SWORD;
string *damage=({"gin","kee","sen"});
string *msg=({
      "���̲�ס������˸�����.\n",
        "�������������ת��Щ�������.\n",
      "���ܵĿ���һ���ӱ�ñ���̹�.\n",
      "�����˺�������Ϯ,������Щή��.\n",
      "����ò��Ϸ���.\n",
      "�����־��Щ�Ժ���.\n",
      "������Լ��챻������.\n",
      });
void create()
{
        set_name(HIG"���Ǻ��⽣"NOR, ({ "ice sword","sword","jian"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG"�����������ƹ���ɽ�����������е������Ƴɵġ�\n"NOR);
                set("material", "stone");
        }
        init_sword(60);
       setup();
}
int init()
{
   add_action("do_wear","wield");
   add_action("do_remove","unwield");
}
int do_wear(string arg)
{
   string str,name;
     if (arg!="ice sword"&&arg!="sword"&&arg!="jian")
                  return 0;
    name=this_object()->query("name");
          str="$N�����ϵĽ�ϻ��ȡ��һ�Ѿ�Ө��͸��"+name+"\n";
  this_object()->set("wield_msg",str);
    remove_call_out("cool");
    call_out("cool",1,this_object());
    return 0;
}
int do_remove(string arg)
{
   string str,name;
     if (arg!="ice sword"&&arg!="sword"&&arg!="jian")
                  return 0;
    name=this_object()->query("name");
    str="$Nһ����,��"+name+"��������Ľ�ϻ.\n";
    this_object()->set("unwield_msg",str);
  remove_call_out("cool");
   return 0;
}
void cool(object ob)
{
   object *inv;
   int i;
   object me=this_player();
   inv=all_inventory(environment(me));
if (!sizeof(inv)) return;
message_vision("$N���ϵ�$n�����̹ǵĺ���\n",this_player(),this_object());
for (i=0;i<sizeof(inv);i++)
    {         if (living(inv[i]))        {
              inv[i]->receive_damage(damage[random(sizeof(damage))],5+random(10));
              tell_object(inv[i],msg[random(sizeof(msg))]);
                          }
    }
call_out("cool",5+random(10),this_object());
 return;
}

