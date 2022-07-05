import discord
from discord.ext import commands
import random
import json
import requests
import os



client = commands.Bot(command_prefix=">")
token = "NzYyMzMxMDMyNDM4ODMzMTUy.X3nmGQ.7LLznZS2G0ulZns15ly7rJDJCSw"



@client.event
async def on_ready():
    await client.change_presence(status=discord.Status.online, activity=discord.Game('Amogus'))
    print("Hey, I'm ready! :)")

@client.event
async def on_member_join(member):
    print(f'{member} has joined a server.')

@client.event
async def on_member_remove(member):
    print(f'{member} has left a server')


@client.command()
async def hello(ctx):
    await ctx.send("Hi")

@client.command()
async def ping(ctx):
    await ctx.send(f'Pong! {round(client.latency * 1000)}ms')

@client.command(aliases=['8ball'])
async def _8ball(ctx, *, question):
    responses = ["It is certain.",
                "It is decidedly so.",
                "Without a doubt.",
                "Yes - definitely.",
                "You may rely on it.",
                "As I see it, yes.",
                "Most likely.",
                "Outlook good.",
                "Yes.",
                "Signs point to yes.",
                "Reply hazy, try again.",
                "Ask again later.",
                "Better not tell you now.",
                "Cannot predict now.",
                "Concentrate and ask again.",
                "Don't count on it.",
                "My reply is no.",
                "My sources say no.",
                "Outlook not so good.",
                "Very doubtful."]
    await ctx.send(f'Question: {question}\nAnswer: {random.choice(responses)}')

@client.command(aliases=['randomdm'])
async def _randomdm(ctx):
    responses = [
        "onetap connect 116.202.241.15:27017",
        "dm connect 116.202.241.15:27051",
        "pistol dm connect 116.202.241.15:27023",
        "wpdm connect 85.10.211.249:27017",
        "arena connect 85.10.211.249:27045"]
    await ctx.send(f'Random server: {random.choice(responses)}')

@client.command()
async def inspire(ctx):
    response = requests.get("https://zenquotes.io/api/random")
    json_data = json.loads(response.text)   
    quote = json_data[0]['q'] + " -" + json_data[0]['a']
    await ctx.send(quote)

#---------------------------------------------------WARFRAME---------------------------------------------------------

#---------------------------------------------------CYCLES---------------------------------------------------------
@client.command()
async def cetus(ctx):
    response = requests.get("https://api.warframestat.us/PC/cetusCycle")
    json_data = json.loads(response.text)
    cetusStatus = 'Current Cetus status: ' + json_data['state'] + '\tTime left: ' + json_data['timeLeft']
    await ctx.send(cetusStatus)

@client.command()
async def cambion(ctx):
    response = requests.get("https://api.warframestat.us/PC/cambionCycle")
    json_data = json.loads(response.text)
    cambionStatus = 'Current Cambion status: ' + json_data['active']
    await ctx.send(cambionStatus)

@client.command()
async def vallis(ctx):
    response = requests.get("https://api.warframestat.us/PC/vallisCycle")
    json_data = json.loads(response.text)
    if bool(json_data['isWarm']) == True:
        vallisStatus = 'Current Orb Vallis status: Warm\tTime left: ' + json_data['timeLeft']
    else:
        vallisStatus = 'Current Orb Vallis status: Cold\tTime left: ' + json_data['timeLeft']
    await ctx.send(vallisStatus)
#------------------------------------------------------------------------------------------------------------
#DARVO DEALS------------
@client.command()
async def darvo(ctx):
    response = requests.get("https://api.warframestat.us/PC/dailyDeals")
    json_data = json.loads(response.text)
    darvoDeals = "Current item: " + json_data[0]['item'] + '\nOriginal price: ' + str(json_data[0]['originalPrice']) + '\nSale price: ' + str(json_data[0]['salePrice']) + '\nDiscount: ' + str(json_data[0]['discount']) + '%'
    await ctx.send(darvoDeals)
#------------------------------BARO----------------------
@client.command()
async def baro(ctx):
    response = requests.get("https://api.warframestat.us/PC/voidTrader")
    json_data = json.loads(response.text)
    baro = "Baro come again in: " + json_data['startString']
    embed = discord.Embed(title=baro)
    await ctx.send(embed=embed)
#------------------------------WARFRAMESTATUS TIMESTAMP--------------------------
@client.command()
async def timestamp(ctx):
    response = requests.get("https://api.warframestat.us/PC/timestamp")
    json_data = json.loads(response.text)
    timestamp = "Warframestat.us timestamp: " + json_data[0]
    await ctx.send(timestamp)
#------------------------------FISSURES--------------------------------------------
@client.command()
async def fissure(ctx,fissureTier):
    print("dolgozom...")
    response = requests.get("https://api.warframestat.us/PC/fissures")
    json_data = json.loads(response.text)
    fissuresOut = []
    for elem in json_data:
        if (fissureTier == elem['tier']):
            fissuresOut.append(elem['node'])
    await ctx.send('jelenlegi ' + fissureTier + ' fissureök: ')
    for elem in fissuresOut:
        fissures = elem
        await ctx.send(fissures)
    print("készen is vagyok :)")

#------------------------------WARFRAME-------------------------------------
#------------------------------WARFRAME MARKET---------------------------------
@client.command()
async def itemId(ctx,item):
    response = requests.get("https://api.warframe.market/v1/items/"+item)
    json_data = json.loads(response.text)
    await ctx.send("Az item ID-je:" + json_data['payload']['item']['id'])

@client.command()
async def lich_weapons(ctx):
    response = requests.get("https://api.warframe.market/v1/lich/weapons")
    json_data = json.loads(response.text)
    for elem in json_data['payload']['weapons']:
        await ctx.send("Weapon Name: "+elem['item_name'])

@client.command()
async def lich_ephemeras(ctx):
    response = requests.get("https://api.warframe.market/v1/lich/ephemeras")
    json_data = json.loads(response.text)
    for elem in json_data['payload']['ephemeras']:
        await ctx.send("Item name:: "+elem['item_name']+'\nElement: '+elem['element'])

@client.command()
async def lich_quirks(ctx):
    response = requests.get("https://api.warframe.market/v1/lich/quirks")
    json_data = json.loads(response.text)
    for elem in json_data['payload']['quirks']:
        await ctx.send("Item name: "+elem['item_name']+'\nElement: '+elem['element']+"\nDescription: "+elem['description'])



#------------------------------GAME-------------------------------------


#------------------------------GAME--------------------------------------





client.run(token)
