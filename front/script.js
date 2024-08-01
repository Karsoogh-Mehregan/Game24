path="http://127.0.0.1:3000/"
document.addEventListener('DOMContentLoaded', function() {
    let chartInstance = null; // Variable to hold the chart instance

    // Function to fetch and display scoreboard data
    function fetchScoreboardData() {
        const scoreboardUrl = path+'teams'; // Replace with your API URL
        fetch(scoreboardUrl)
            .then(response => response.json())
            .then(data => {
                const tbody = document.getElementById('scoreboard-body');
                tbody.innerHTML = ''; // Clear existing rows

                data.forEach(item => {
                    const row = document.createElement('tr');

                    row.innerHTML = `
                        <td>${item.name}</td>
                        <td>${item.score}</td>
                        <td>${item.status}</td>
                    `;

                    tbody.appendChild(row);
                });
            })
            .catch(error => {
                console.error('Error fetching scoreboard data:', error);
            });
    }

    // Function to initialize or update the chart
    function fetchChartAndLeverageData() {
        const chartUrl = path+'ba'; // Replace with your API URL
        const leverageUrl = path+'get-leverages'; // Replace with your API URL
        let latestValue = 'Loading...';

        Promise.all([
            fetch(chartUrl).then(response => response.json()),
            fetch(leverageUrl).then(response => response.json())
        ])
        .then(([chartData, leverageData]) => {
            const values = chartData.map(item => item.value);
            const labels = values.map((_, index) => `Point ${index + 1}`);
            
            // Highlight the last data point
            const lastIndex = values.length - 1;
            latestValue = values[lastIndex];

            const ctx = document.getElementById('stockChart').getContext('2d');

            if (!chartInstance) {
                // Create a new chart if it does not exist
                chartInstance = new Chart(ctx, {
                    type: 'line',
                    data: {
                        labels: labels,
                        datasets: [{
                            label: 'Stock Trend',
                            data: values,
                            borderColor: 'rgba(75, 192, 192, 1)',
                            backgroundColor: 'rgba(75, 192, 192, 0.2)',
                            borderWidth: 2,
                            pointBackgroundColor: 'rgba(75, 192, 192, 1)',
                            pointBorderColor: 'rgba(255, 255, 255, 1)',
                            pointRadius: 4
                        }]
                    },
                    options: {
                        responsive: true,
                        animation: {
                            duration: 0 // Disable initial animation
                        },
                        scales: {
                            x: {
                                beginAtZero: true
                            },
                            y: {
                                beginAtZero: true
                            }
                        }
                    }
                });
            } else {
                // Update the chart data without reinitializing
                chartInstance.data.labels = labels;
                chartInstance.data.datasets[0].data = values;
                chartInstance.update(); // Update the chart
            }

            // Update the page with leverage and latest value information
            document.getElementById('lev1-status').textContent = leverageData.lev1 ? 'Active' : 'Inactive';
            document.getElementById('lev2-status').textContent = leverageData.lev2 ? 'Active' : 'Inactive';
            document.getElementById('lev3-status').textContent = leverageData.lev3 ? 'Active' : 'Inactive';
            document.getElementById('lev4-status').textContent = leverageData.lev4 ? 'Active' : 'Inactive';

            // Display the latest value in the element with ID 'last'
            document.getElementById('last').textContent = `Latest Value: ${latestValue}`;
        })
        .catch(error => {
            console.error('Error fetching chart or leverage data:', error);
        });
    }

    // Initial data fetch
    fetchScoreboardData();
    fetchChartAndLeverageData();

    // Set up the interval to call fetchScoreboardData and fetchChartAndLeverageData every 3 seconds
    setInterval(function() {
        console.log(1);
        fetchScoreboardData();
        fetchChartAndLeverageData();
    }, 3000); // 3,000 milliseconds = 3 seconds
});
