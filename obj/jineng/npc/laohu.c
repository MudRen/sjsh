// laofu.c �ϻ�

#include <ansi.h>;
int big_blowing();
inherit NPC;

void create()
{
        set_name("�ϻ�", ({ "laohu", "tiger","hu" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", @LONG
һֻ����ͻ�����ΰ���ˡ�

         _.-'"''--..__.("\-''-'") 
 ('.__.-' (  *  ) .-'    ( @ _@' /{��Ҫ����Ҫ��������ûϴ���ǣ�}     
  `-..-''.' _.'  (   _.  `(._Y_)/
         `. `._`--\  \_-.._`--'.._
          `-.!))  `.(il)   ''-.(li)



LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);
        set("neili",800);
        set("jiali",100);
        set("max_neili",800);
        set("jingli",500);
        set("max_jingli",500);

        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 1000);

        setup();

        set("chat_chance", 10);
        carry_object("/obj/jineng/medicals/hugu");
        set("chat_msg", ({
                "�ϻ��ڿ�Ѳ���ŵ�����������ҳ���\n",
                "�ϻ����쳤Х������ɽ�ȣ���Ҷ��׹��\n",
        }) );
}

void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="hugu" || inv[i]->query("id")=="hu gu")
                {
                   inv[i]->move(me);
                   message_vision("$n������˷��۵��ϻ�,���ͳ����Ӹ����,������һ�黢��,��æ�����˿ڴ��\n",this_object(),me);
         }
        }
  }
     destruct(this_object());
}

