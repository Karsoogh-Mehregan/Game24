# Generated by Django 4.2.13 on 2024-08-01 12:27

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('main', '0016_allinfo_alter_team_a_alter_team_b'),
    ]

    operations = [
        migrations.AlterField(
            model_name='allinfo',
            name='demand',
            field=models.FloatField(default=0),
        ),
        migrations.AlterField(
            model_name='allinfo',
            name='supply',
            field=models.FloatField(default=0),
        ),
    ]