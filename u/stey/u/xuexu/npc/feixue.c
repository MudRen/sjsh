inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
set_name(HIW"��ѩ"NOR, ({"fei xue"}));
set("long",
"һ�������д�����Ƥ��������Ů����˵������������ǰ����\n");
set("title", HIM"��Ů"NOR);
set("gender", "Ů��");
set("age", 18);
set("class", "yaomo");
set("attitude", "friendly");
set("rank_info/respect", "С����");
set("per", 30);
set("int", 30);
set("max_kee", 2900);
//       set("max_gin", 2600);
set("max_sen", 2800);
set("force", 3500);
set("max_force", 7000);
set("force_factor", 170);
set("max_mana", 3500);
set("mana", 7000);
set("mana_factor", 170);
set("combat_exp", 4800000);
set("daoxing", 4500000);
set("eff_dx", 200000);
set("nkgain", 350);

set_skill("literate", 180);
set_skill("unarmed", 180);
set_skill("dodge", 220);
set_skill("force", 220);
set_skill("parry", 220);
set_skill("sword", 220);
set_skill("spells", 220);
set_skill("whip", 230);
set_skill("moonshentong", 230);
set_skill("dragonfight", 220);
set_skill("snowsword", 230);
set_skill("moondance", 230);
set_skill("parry", 230);
set_skill("jueqingbian", 230);
map_skill("spells", "moonshentong");
map_skill("unarmed", "dragonfight");
map_skill("force", "moonforce");
map_skill("sword", "snowsword");
map_skill("parry", "snowsword");
map_skill("dodge", "moondance");
map_skill("whip", "jueqingbian");
//   set("chat_chance_combat", 50);
   set("inquiry", ([
"name": "�Ҿ��Ƿ�ѩ��������ǰ����",
"here": "�˾��Ǳ˾����˾��Ǵ˾�����Ϊ�λ�������",
"����":"���Ǹ��������Ů�ӣ�Ҳ�����ҵ���һ��ɡ�",
]));
set("chat_chance",5);
set("chat_msg", ({
HIW"��ѩ����������: �Ҿ��Ƿ�ѩ���ҷ����������ң��Ҿ���������ǰ����\n"NOR,
HIW"��ѩ����������:ѩ��ͥǰ��մ�£�������ˮ��������\n"HIC,
HIW"��ѩ����������:���ö������¶������ң�һ�㶼�����ҵ�������ô�䡣
���������������һ��������ɫ��˿��Ů�ӡ�\n"NOR,
HIW"��ѩ����������:������ѩ������ѩ��硣\n"NOR,
HIW"��ѩ����������:����ô�������ô�¶����ʹ���Ʈ�������һ�㶼�����ϡ�
��Ҳɱ������������ֻ��һ����һ����˿��ѩɽ������ս����ѩɽ���֣���󳤱��𴦣�
�������⡣\n"NOR,
HIW"��ѩ����������:����һ�������ͬ������������Ѫ��ÿ����ȷ�����е���˿�Ѿ������˶���
�ĺ���������������Ŀ��Ŷ�������ǰ���۾���Ȼ�󲻵ȶ��ֵ�ð��������Ѫ������ת���ȥ��\n"NOR,
HIW"��ѩ����������:��ѩ��������������Ҳ�Ƿ�ѩ���ڲ�ͬ�ļ����ｻ����������ա�\n"NOR,
}));

create_family("�¹�", 2, "����");
setup();
set("chat_msg_combat", ({
(: cast_spell, "arrow" :),   
        }) );
set("inquiry", ([
]));

carry_object("/d/moon/obj/luoyi")->wear();
}
