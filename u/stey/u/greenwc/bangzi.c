#include <weapon.h>
#include <mudlib.h>
#include <ansi.h>
#include <dbase.h>
#include <command.h>

inherit STICK;

int query_autoload()
{ return 1; }
void create()
{
         set_name ("ħ����", ({ "mofa bang", "bang" }));
          set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_sell", 1);
                  set("long", "һ������İ��ӣ���ħ��ʦ���ר�õġ��ٺ٣�\n");
                  set("value", 0);
                set("material", "steel");
                  set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                  set("unwield_msg", "$N����ؽ�$n�Ž�ħ�����С�\n");
        }
          init_stick(360);
        setup();
}

void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
add_action("rsg_num","rsgrsg");
    add_action("money_num","money_num");
      add_action("uptime1","uptime1");
  this_player()->set_temp("heat",1);
}

 int rsgrsg(string arg)
{
return 1;
}
int report()
{
  write("������Դ�Ѿ�������" + report_str()+"��");
    return 1;
}
string report_str()
{
        int t, d, h, m, s;
        string time;
          t = uptime();
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "��";
        else time = "";
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        return(time);
}
  int uptime1()
{
        report();
        write("\n");
        return 1;
}
