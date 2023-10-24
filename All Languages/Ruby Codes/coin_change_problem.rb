def coin_change(coins, amount)
  dp = Array.new(amount + 1, Float::INFINITY)
  dp[0] = 0

  coins.each do |coin|
    (coin..amount).each do |i|
      dp[i] = [dp[i], dp[i - coin] + 1].min
    end
  end

  dp[amount] == Float::INFINITY ? -1 : dp[amount]
end

# Take user input for coin denominations
puts "Enter coin denominations separated by spaces:"
coins = gets.chomp.split.map(&:to_i)

# Take user input for the target amount
puts "Enter the target amount:"
amount = gets.chomp.to_i

result = coin_change(coins, amount)

if result == -1
  puts "It's not possible to make change for the given amount with the provided coins."
else
  puts "Minimum number of coins needed: #{result}"
end
