import Data.Time

main :: IO ()
main = do 
  !startTime <- getCurrentTime
  let !result = solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  --putStrLn ("Solution: " ++ (show result))
  --putStrLn ("Execution Time: " ++ (show diffTime))
  putStrLn $ (reverse.tail.reverse) (show diffTime)

solution :: Int
solution = sum $ map size [1..1000]

units :: Int -> Int
units n = length $ ["","one","two","three","four","five","six","seven","eight","nine"] !! n 

tens :: Int -> Int
tens n = length $ ["","","twenty","thirty","forty","fifty","sixty","seventy","eigthy","ninety"] !! n

last2 :: Int -> Int
last2 n | l == 0            = 0 
        | l > 9  && l < 20  = s + (length $ ["ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"] !! (l-10))
        | l <= 9 || l >= 20 = s + (tens (l `div` 10) + units (l `mod` 10))
        where l = n `mod` 100 
              s = if n < 100 then 0 else 3

hundreds :: Int -> Int
hundreds n | n `mod` 1000 > 99    = last2 ((n `mod` 1000) `div` 100) + 7
           | otherwise = 0

thousands :: Int -> Int
thousands n | n > 999   = last2 ((n `div` 1000) `mod` 10) + 8
            | otherwise = 0

size n = thousands n + hundreds n + last2 n

