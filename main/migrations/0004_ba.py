# Generated by Django 4.2.13 on 2024-07-30 05:50

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('main', '0003_alter_duel_winner_alter_team_stat'),
    ]

    operations = [
        migrations.CreateModel(
            name='BA',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('value', models.FloatField()),
                ('time', models.DateTimeField(auto_now_add=True)),
            ],
        ),
    ]